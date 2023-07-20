/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

int execute_command(char *command)
{
        char **args = NULL;
        char *temp = NULL;
        char *pwd = NULL;

        pwd = getcwd(pwd, 0);
        args = str_to_array(command, ' ');
        temp = malloc(sizeof(char) *
        ((strlen(pwd) + strlen(args[0])) + 2));
        temp = strcpy(temp, pwd);
        temp = strcat(temp, "/");
        temp = my_strnncat(temp, args[0], 2, strlen(temp));
        temp[strlen(temp)] = '\0';
        execve(temp, args, NULL);
        free(temp);
        free(args);
        free(pwd);
    return 0;
}
