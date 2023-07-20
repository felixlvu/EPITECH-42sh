/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

int exe_logic_and(Mysh *mysh, char *command)
{
    char *token = NULL;
    int i = 0;
    char **test = NULL;

    test = malloc(sizeof(char *) * (strlen(command) + 1));
    token = strtok(command, "&");
    while (token != NULL) {
        test[i] = token;
        i++;
        token = strtok(NULL, "&");
    }
    test[i] = NULL;

    if (find_command(test[0], mysh) == 1) {
        return 1;
    }
    find_command(test[1], mysh);
    free(test);
    free(token);
    return 0;
}

int check_logic_and(char **args, int i)
{
    int j = 0;

    for (j = 0; args[i][j] != '\0'; j++) {
        if (args[i][j] == '&' && args[i][j + 1] == '&') {
            return 1;
        }
    }

    return 0;
}

int search_logic_and(char **args)
{
    int i = 0;

    for (i = 0; args[i] != NULL; i++) {
        if (check_logic_and(args, i) == 1)
            return 1;
    }

    return 0;
}
