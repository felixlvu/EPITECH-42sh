/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <string.h>

void remove_space(Mysh *mysh, char **test)
{
    char *token;
    mysh->pipes = malloc(sizeof(Pipe) * mysh->num_pipes);
    int p = 0;
    for (p = 0; p < mysh->num_pipes; p++) {
        mysh->pipes[p].args = malloc(sizeof(char *) * (strlen(test[p]) + 1));
        token = strtok(test[p], " \t\r\n\a");
        int f = 0;
        while (token != NULL) {
            mysh->pipes[p].args[f] = token;
            f++;
            token = strtok(NULL, " \t\r\n\a");
        }
        mysh->pipes[p].args[f] = NULL;
    }
    mysh->num_cmd = p + 1;
}

char **separate_pipes(Mysh *mysh, char *command, int pipes)
{
    char **test = NULL;
    char *token;
    int i = 0;

    test = malloc(sizeof(char *) * (pipes + 2));
    token = strtok(command, "|");
    while (token != NULL) {
        test[i] = token;
        i++;
        token = strtok(NULL, "|");
    }
    test[i] = NULL;
    if ((pipes + 1) != i) {
        printf("Invalid null command.\n");
        mysh->retur = 1;
        return NULL;
    }
    mysh->num_pipes = i;
    return test;
}

int fill_args(Mysh *mysh, char *command)
{
    char **test = NULL;
    int pipes = 0;

    trim(command);
    if (command[0] == '|') {
        printf("Invalid null command.\n");
        mysh->retur = 1;
        return 1;
    }
    for (int j = 0; command[j] != '\0'; j++) {
        if (command[j] == '|')
            pipes++;
    }
    test = separate_pipes(mysh, command, pipes);
    if (test == NULL)
        return 1;
    remove_space(mysh, test);
    free(test);
    return 0;
}
