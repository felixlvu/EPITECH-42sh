/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "mym.h"

int open_output_left(char **args, int fd)
{
    fd = open(args[1], O_RDONLY);
    if (fd < 0) {
        printf("Ambiguous output redirect.\n");
        return 1;
    }
    dup2(fd, STDIN_FILENO);
    return 0;
}

char **separate_direc_left(char **args, char *command, Mysh *mysh, int direc)
{
    char *token = NULL;
    int i = 0;
    args = malloc(sizeof(char *) * (direc + 2));
    token = strtok(command, "<");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, "<");
    }
    args[i] = NULL;
    trim(args[0]);
    if (i == 1)
        i = 2;
    if (args[i - 1] == NULL || args[i - 1][0] == '\0') {
        mysh->retur = 1;
        printf("Missing name for redirect.\n");
        return NULL;
    }
    free(token);
    return args;
}

char **check_error_left(char **args, char *command, Mysh *mysh)
{
    int direc = 0;

    trim(command);
    if (command[0] == '<'){
        mysh->retur = 1;
        printf("Invalid null command.\n");
        return NULL;
    }
    for (int z = 0; command[z] != '\0'; z++) {
        if (command[z] == '<')
            direc++;
    }
    args = separate_direc_left(args, command, mysh, direc);
    if (args == NULL)
        return NULL;
    trim(args[1]);
    return args;
}

int exe_redirec_left(Mysh *mysh, char *command)
{
    int stdout_copy = dup(STDIN_FILENO);
    char **args = NULL;
    int fd = 0;

    args = check_error_left(args, command, mysh);
    if (args == NULL) {
        mysh->retur = 1;
        return 1;
    }
    if (open_output_left(args, fd) == 1)
        return 1;
    if (find_command(args[0], mysh) == 1)
        return 1;
    dup2(stdout_copy, STDIN_FILENO);
    close(stdout_copy);
    free(args);
    return 0;
}
