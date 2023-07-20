/*
** EPITECH PROJECT, 2023
** 42sh
** File description:
** backslash
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mym.h"

int backslash_command(char *line, Mysh *mysh)
{
    char **tab = NULL;

    tab = str_to_array(line, '\\');
    find_command(tab[0], mysh);
    return 0;
}

int backslash_simple(char *line, Mysh *mysh)
{
    char *command = NULL; char *cpyline = NULL; char *cpyline2 = NULL;
    size_t size = 0;
    if (strlen(line) == 0)
        return 0;
    cpyline = strdup(line);
    cpyline2 = strdup(line);
    cpyline = str_clean(cpyline);
    cpyline2 = strcleantok(cpyline2);
    if (strncmp(cpyline2, "\\\0", 2) == 0) {
        printf("? ");
        while (getline(&command, &size, stdin) == -1)
            return 0;
        printf("\n");
        find_command(command, mysh);
        return 1;
    }
    if (cpyline[0] == '\\') {
        backslash_command(cpyline, mysh);
        return 1;
    } return 0;
}