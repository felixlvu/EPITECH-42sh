/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "../include/mym.h"
#include "../include/gestion_line.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void init_42sh(char** env , Mysh *mysh)
{
    create_new_env(env, mysh);
    find_elements(env, mysh);
    init_path(mysh);
    mysh->find_oldpwd = 0;
    mysh->exit = 0;
    print_welcome_msg();
}

int main_loop(char **env, Mysh *mysh)
{
    char command[4096];
    line_history *history = NULL;
    line_history *new_elm = NULL;

    history = def_history(); init_42sh(env, mysh);
    if (history == NULL)
        return (84);
    while (mysh != NULL && mysh->exit == 0) {
        print_prompt(1);
        new_elm = get_line(new_elm, mysh);
        history = put_in_history(history, new_elm);
        strcpy(command, history->history_line);
        if (strncmp(command, "history", 7) == 0
        || backslash_simple(command, mysh) == 1) {
        } else {
            find_command(command, mysh);
        }
    }
    free_history(history);
    return 0;
}
