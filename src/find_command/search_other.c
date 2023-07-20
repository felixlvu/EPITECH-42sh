/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "mym.h"

int search_all_redirec(Mysh *mysh, char **args, char *arg_dup)
{
    if (search_redirec(args) == 1) {
        if (exe_redirec(mysh, arg_dup) == 1) {
            return 1;
        }
        return 2;
    }
    if (search_redirec_left(args) == 1) {
        if (exe_redirec_left(mysh, arg_dup) == 1) {
            return 1;
        }
        return 2;
    }
    return 0;
}

int search_logic(Mysh *mysh, char **args, char *arg_dup)
{
    if (search_logic_and(args) == 1) {
        if (exe_logic_and(mysh, arg_dup) == 1) {
            return 1;
        }
        return 2;
    }
    if (search_logic_or(args) == 1) {
        if (exe_logic_or(mysh, arg_dup) == 1) {
            return 1;
        }
        return 2;
    }
    return 0;
}

int search_operator(Mysh *mysh, char **args, char *arg_dup, char *arg_dup2)
{
    if (search_separator(args) == 1) {
        if (exe_separator(mysh, arg_dup2) == 1) {
            free(arg_dup2);
            return 1;
        }
        free(arg_dup2);
        return 2;
    }
    free(arg_dup2);
    if (search_pipe(args) == 1) {
        if (exe_pipe(mysh, arg_dup) == 1) {
            return 1;
        }
        return 2;
    }
    return 0;
}

int search_other(Mysh *mysh, char **args, char *arg_dup)
{
    char *arg_dup2 = NULL;
    int ret = 0;

    arg_dup2 = strdup(arg_dup);
    ret = search_operator(mysh, args, arg_dup, arg_dup2);
    if (ret != 0) {
        return ret;
    }
    ret = search_logic(mysh, args, arg_dup);
    if (ret != 0) {
        return ret;
    }
    ret = search_all_redirec(mysh, args, arg_dup);
    if (ret != 0) {
        return ret;
    }
    if (args[0] == NULL)
        return 2;
    return 0;
}
