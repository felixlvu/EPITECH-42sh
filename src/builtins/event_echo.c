/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>


void print_noquote_echo(char **args)
{
    int i = 0;

    for (i = 1; args[i] != NULL; i++) {
            printf("%s", args[i]);
            if (args[i + 1] != NULL)
                printf(" ");
    }
}

void print_args_echo(char **args, int i)
{
    int j = 0;

    for (j = 0; args[i][j] != '\0'; j++) {
        if (args[i][j] != '"')
            printf("%c", args[i][j]);
    }
}

void print_quote_echo(char **args)
{
    int i = 0;

    for (i = 1; args[i] != NULL; i++) {
        print_args_echo(args, i);
        if (args[i + 1] != NULL)
            printf(" ");
    }
}

void event_echo(Mysh *mysh, char **args)
{
    if (args[1] == NULL) {
        printf("\n");
        return;
    }
    if (strcmp(args[1], "$?") == 0) {
        printf("%d\n", mysh->retur);
        return;
    }
    if (strcmp(args[1], "$HOME") == 0) {
        printf("%s\n", mysh->home);
        return;
    }
    if (args[1][0] == '"') {
        print_quote_echo(args);
    } else {
        print_noquote_echo(args);
    }
    printf("\n");
}
