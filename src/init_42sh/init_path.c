/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

void init_path(Mysh *mysh)
{
    int i = 0;
    mysh->path = NULL;

    for (i = 0; mysh->new_env[i] != NULL; i++) {
        if (strncmp(mysh->new_env[i], "PATH=", 5) == 0) {
            mysh->path = malloc(sizeof(char) * (strlen(mysh->new_env[i])));
            mysh->path = my_strnncat(mysh->path, mysh->new_env[i], 5, 0);
        }
    }
    if (mysh->path != NULL) {
        mysh->path[strlen(mysh->path)] = '\0';
    } else {
        mysh->path = malloc(sizeof(char) * 6);
        mysh->path = strcpy(mysh->path, "/bin/");
    }
}
