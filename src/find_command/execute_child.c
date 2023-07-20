/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/


#include "mym.h"
#include <string.h>

int execute_child(char *command, Mysh *mysh, char **args)
{
    char *temp = NULL;
    int ret = 0;

    temp = find_command_path(mysh, args);

    if (args[0][0] == '.' && args[0][1] == '/') {
        ret = execute_command(command);
    } else {
        if (execve(temp, args, NULL) == -1) {
        printf("%s", args[0]);
        printf(": Command not found.\n");
        return 0;
        }
    }
    return ret;
}
