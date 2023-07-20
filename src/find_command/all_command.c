/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

char **init_args(char **args, char *command)
{
    char *token = NULL;
    int i = 0;

    args = malloc(sizeof(char *) * (strlen(command) + 1));
    token = strtok(command, " \t\r\n\a");
    while (token != NULL) {
        args[i] = token;
        i++;
        token = strtok(NULL, " \t\r\n\a");
    }
    args[i] = NULL;
    free(token);

    return args;
}

int find_command(char *command, Mysh *mysh)
{
    char *args_dup = strdup(command);
    char **args = NULL;
    char *path = NULL;
    mysh->pwd = NULL;
    int ret = 0;
    args = init_args(args, command);
    ret = search_other(mysh, args, args_dup);
    free(args_dup);
    if (ret == 1)
        return 1;
    if (ret == 2)
        return 0;
    if (all_builtins(args, mysh) == 2)
        return 0;
    if (search_env_var(mysh, command) == 1)
        return 0;
    path = find_command_path(mysh, args);
    ret = check_child_command(command, args, path, mysh);
    mysh->retur = ret;
    return ret;
}
