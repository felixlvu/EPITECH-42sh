/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>

int check_var_stat(char *var)
{
    struct stat info;

    if (stat(var, &info) != 0) {
        free(var);
        return 1;
    } else {
        if (S_ISDIR(info.st_mode)) {
            printf(": Is a directory  \n");
        } else {
            printf(": No such file or directory\n");
        }
        free(var);
        return 1;
    }
    return 0;
}

int print_env_var(Mysh *mysh, char *command, char *var_env, int i)
{
    char *var = NULL;
    int j = 0;

    if (strncmp(var_env, mysh->new_env[i], strlen(var_env)) == 0) {
        j = strlen(command);
        var = malloc(sizeof(char) * (strlen(mysh->new_env[i]) + 1));
        my_strnncat(var, mysh->new_env[i], j, 0);
        printf("%s", var);
        if (access(var, X_OK) != 0) {
            printf(": Permission denied.\n");
            free(var);
            return 1;
        }
        if (check_var_stat(var) == 1)
            return 1;
    }
    free(var);
    return j;
}

int move_env(Mysh *mysh, char *command, char *var_env, int i)
{
    for (i = 0; mysh->new_env[i] != NULL; i++) {
        if (print_env_var(mysh, command, var_env, i) == 1)
            return 1;
    }
    return 0;
}

int search_env_var(Mysh *mysh, char *command)
{
    char *var_env = NULL;
    int i = 0;

    if (command[0] == '$') {
        var_env = strdup(&command[1]);
        if (move_env(mysh, command, var_env, i) == 1) {
            free(var_env);
            return 1;
        }
    }
    free(var_env);
    return 0;
}
