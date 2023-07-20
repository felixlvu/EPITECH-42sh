/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

void find_elements(char **env, Mysh *mysh)
{
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "HOME", 4) == 0)
            mysh->find_env = i;
    }
    mysh->home = malloc(sizeof(char *) * (strlen(env[mysh->find_env]) - 5));
    my_strnncat(mysh->home, env[mysh->find_env], 5, 0);
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "PWD", 3) == 0) {
            mysh->find_pwd = i;
        }
    }
    for (int i = 0; env[i] != NULL; i++) {
        if (strncmp(env[i], "OLDPWD", 6) == 0) {
            mysh->find_oldpwd = i;
        }
    }
}
