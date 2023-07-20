/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

int search_pipe_args(char **args, int i)
{
    int j = 0;

    for (j = 0; args[i][j] != '\0'; j++) {
        if (args[i][j] == '|' &&
(args[i][j - 1] != '|' && args[i][j + 1] != '|')) {
            return 1;
        }
    }
    return 0;
}

int search_pipe(char **args)
{
    int i = 0;

    for (i = 0; args[i] != NULL; i++) {
        if (search_pipe_args(args, i) == 1)
            return 1;
    }
    return 0;
}
