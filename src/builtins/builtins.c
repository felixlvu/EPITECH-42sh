/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

int builtins_env(char **args, Mysh *mysh)
{
    if (strcmp(args[0], "env") == 0) {
        print_env(mysh);
        return 2;
    }
    if (strcmp(args[0], "setenv") == 0) {
        event_setenv(mysh, args);
        return 2;
    }
    if (strcmp(args[0], "unsetenv") == 0) {
        mysh->new_env = event_unsetenv(mysh, args);
        return 2;
    }
    if (strncmp(args[0], "alias", 5) == 0) {
        alias(args);
        return 2;
    }
    return 0;
}

void free_all_exit(char **args, Mysh *mysh)
{
    int i = 0;

    for (i = 0; mysh->new_env[i] != NULL; i++)
        free(mysh->new_env[i]);
    free(mysh->new_env);
    free(mysh->home);
    free(mysh->path);
    free(args);
    free(mysh);
}

int all_builtins(char **args, Mysh *mysh)
{
    if (strcmp(args[0], "cd") == 0) {
        execute_cd(mysh, args);
        return 2;
    }
    if (strcmp(args[0], "exit") == 0) {
        free_all_exit(args, mysh);
        exit(0);
    }
    if (builtins_env(args, mysh) == 2)
        return 2;
    if (strcmp(args[0], "echo") == 0) {
        event_echo(mysh, args);
        return 2;
    }
    if (strncmp(args[0], "unalias", 7) == 0) {
        unalias(args);
        return 2;
    }
    return 0;
}
