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

int open_output(int type, char **args, int fd)
{
    if (type == 1) {
        fd = open(args[1], O_WRONLY | O_CREAT | O_APPEND,
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    } else {
        fd = open(args[1], O_WRONLY | O_CREAT | O_TRUNC,
S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    }
    if (fd < 0) {
        printf("Ambiguous output redirect.\n");
        return 1;
    }
    dup2(fd, STDOUT_FILENO);
    return 0;
}

char **separate_direc(char **args, char *command, Mysh *mysh, int direc)
{
    char *token = NULL;
    int i = 0;
    args = malloc(sizeof(char *) * (direc + 2));
    token = strtok(command, ">");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, ">");
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

char **check_error(char **args, char *command, Mysh *mysh)
{
    int direc = 0;

    trim(command);
    if (command[0] == '>'){
        mysh->retur = 1;
        printf("Invalid null command.\n");
        return NULL;
    }
    for (int z = 0; command[z] != '\0'; z++) {
        if (command[z] == '>')
            direc++;
    }
    args = separate_direc(args, command, mysh, direc);
    if (args == NULL)
        return NULL;
    trim(args[1]);
    return args;
}

int find_type(char *command, int type)
{
    for (int j = 0; command[j] != '\0'; j++) {
        if (command[j] == '>' && command[j + 1] == '>')
            type = 1;
    }
    return type;
}

int exe_redirec(Mysh *mysh, char *command)
{
    int stdout_copy = dup(STDOUT_FILENO);
    char **args = NULL;
    int type = 0;
    int fd = 0;

    type = find_type(command, type);
    args = check_error(args, command, mysh);
    if (args == NULL) {
        mysh->retur = 1;
        return 1;
    }
    if (open_output(type, args, fd) == 1)
        return 1;
    if (find_command(args[0], mysh) == 1)
        return 1;
    dup2(stdout_copy, STDOUT_FILENO);
    close(stdout_copy);
    free(args);
    return 0;
}
