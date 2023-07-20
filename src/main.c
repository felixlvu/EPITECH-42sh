/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include "gestion_line.h"

int main(int arc, char *arv[], char **env)
{
    Mysh *mysh;
    int ret = 0;
    mysh = malloc(sizeof(Mysh));

    if (mysh == NULL)
        return (84);
    if (env[0] == NULL)
        return (84);
    if (arc != 1 || arv[1] != NULL)
        return (84);
    def_term();
    ret = main_loop(env, mysh);
    if (mysh->retur != 0)
        return (mysh->retur);
    return (ret);
}
