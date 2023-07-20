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

int check_redirec_left(char **args, int i)
{
    int j = 0;

    for (j = 0; args[i][j] != '\0'; j++) {
        if (args[i][j] == '<') {
            return 1;
        }
    }

    return 0;
}

int search_redirec_left(char **args)
{
    int i = 0;

    for (i = 0; args[i] != NULL; i++) {
        if (check_redirec_left(args, i) == 1) {
            return 1;
        }
    }

    return 0;
}
