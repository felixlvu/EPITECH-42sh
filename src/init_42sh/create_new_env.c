/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

void create_new_env(char **env, Mysh *mysh)
{
    int len_env = 0;
    int i = 0;

    for (len_env = 0 ; env[len_env] != NULL; len_env++);

    mysh->new_env = malloc(sizeof(char *) * (len_env + 1));
    for (i = 0; env[i] != NULL; i++) {
        mysh->new_env[i] = malloc(sizeof(char) * strlen(env[i]) + 1);
        mysh->new_env[i] = strcpy(mysh->new_env[i], env[i]);
    }
    mysh->new_env[i] = NULL;
}
