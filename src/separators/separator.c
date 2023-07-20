/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

int move_args(char **args, int j, int i)
{
    for (j = 0; args[i][j] != '\0'; j++) {
        if (args[i][j] == ';') {
            return 1;
        }
    }
    return 0;
}

int search_separator(char **args)
{
    int i = 0;
    int j = 0;

    for (i = 0; args[i] != NULL; i++) {
        if (move_args(args, j, i) == 1)
            return 1;
    }
    return 0;
}

int exe_separator(Mysh *mysh, char *command)
{
    char *token = NULL;
    int i = 0;
    char **test = NULL;

    test = malloc(sizeof(char *) * (strlen(command) + 1));
    token = strtok(command, ";");
    while (token != NULL) {
        test[i] = token;
        i++;
        token = strtok(NULL, ";");
    }
    test[i] = NULL;
    for (int j = 0; test[j] != NULL; j++) {
        if (find_command(test[j], mysh) == 1)
            return 1;
    }
    free(test);
    free(token);
    return 0;
}
