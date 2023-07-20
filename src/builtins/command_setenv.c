/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

void exit_multi_args(Mysh *mysh, char **args, int i)
{
    if (args[2] == NULL) {
        mysh->new_env[i] = malloc(sizeof(char) * (strlen(args[1]) + 2));
        mysh->new_env[i] = strcpy(mysh->new_env[i], args[1]);
        mysh->new_env[i] = strcat(mysh->new_env[i], "=");
        mysh->new_env[i] = strcat(mysh->new_env[i], "\0");
    } else {
        mysh->new_env[i] = malloc(sizeof(char) *
        (strlen(args[1]) + strlen(args[2]) + 2));
        mysh->new_env[i] = strcpy(mysh->new_env[i], args[1]);
        mysh->new_env[i] = strcat(mysh->new_env[i], "=");
        mysh->new_env[i] = strcat(mysh->new_env[i], args[2]);
        mysh->new_env[i] = strcat(mysh->new_env[i], "\0");
    }
}

int exit_event(Mysh *mysh, char **args)
{
    for (int i = 0; mysh->new_env[i] != NULL; i++) {
        if (strncmp(mysh->new_env[i], args[1], strlen(args[1])) == 0 &&
        mysh->new_env[i][strlen(args[1])] == '=') {
            free(mysh->new_env[i]);
            exit_multi_args(mysh, args, i);
            return 1;
        }
    }
    return 0;
}

char **check_args(char **args, int len, char **temp)
{
    if (args[2] == NULL) {
        temp[len] = malloc(sizeof(char) * (strlen(args[1]) + 2));
        temp[len][strlen(args[1])] = '\0';
    } else {
        temp[len] = malloc(sizeof(char) *
        (strlen(args[1]) + strlen(args[2]) + 2));
        temp[len][strlen(args[1]) + (strlen(args[2]) + 1)] = '\0';
    }

    temp[len] = strcpy(temp[len], args[1]);
    temp[len] = strcat(temp[len], "=");

    return temp;
}

int check_valid_args(char **args)
{
    if (args[1] != NULL && args[1][0] > '0' && args[1][0] < '9') {
        printf("setenv: Variable name must begin with a letter.\n");
        return 1;
    }
    for (int i = 0; args[1][i] != '\0'; i++) {
        if (args[1][i] < 48 || (args[1][i] > 57 && args[1][i] < 65) ||
        (args[1][i] > 90 && args[1][i] < 97) || args[1][i] > 122) {
            printf("setenv: Variable name must contain ");
            printf("alphanumeric characters.\n");
            return 1;
        }
    }
    return 0;
}

void event_setenv(Mysh *mysh, char **args)
{
    char **temp = NULL;
    int len = 0;

    if (args[1] == NULL) {
        print_env(mysh);
        return;
    }
    if (exit_event(mysh, args) == 1 || check_valid_args(args) == 1)
        return;
    temp = copy_array_add(mysh->new_env, 1);
    for (len = 0; temp[len] != NULL; len++);

    free(temp[len]);
    temp = check_args(args, len, temp);
    if (args[2] != NULL)
        temp[len] = strcat(temp[len], args[2]);

    temp[len + 1] = NULL;
    mysh->new_env = copy_array(temp);
}
