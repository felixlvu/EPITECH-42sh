/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

char *strcpycwd(char *dest, char const *src)
{
    int i = 0;

    while (src[i] != '\0') {
        dest[i] = src[i];
        i++;
    }
    dest[i] = '\0';
    return (dest);
}

void change_pwd(Mysh *mysh)
{
    char *cwd = NULL;
    char *temp = NULL;

    cwd = getcwd(cwd, 0);

    temp = malloc(sizeof(char) * (strlen(cwd) + 5));
    temp = strcpycwd(temp, "PWD=");
    temp = strcat(temp, cwd);

    for (int i = 4; mysh->new_env[mysh->find_pwd][i] != '\0'; i++)
        mysh->new_env[mysh->find_pwd][i] = '\0';

    free(mysh->new_env[mysh->find_pwd]);
    mysh->new_env[mysh->find_pwd] = malloc(sizeof(char) * (strlen(cwd) + 5));

    mysh->new_env[mysh->find_pwd] = strcpycwd(mysh->new_env[mysh->find_pwd],
    temp);
    free(cwd);
    free(temp);
}

void change_oldpwd(Mysh *mysh, char *cwd)
{
    char *temp = NULL;
    int i = 0;
    if (mysh->find_oldpwd == 0) {
        mysh->find_oldpwd = mysh->find_pwd;
    }

    temp = malloc(sizeof(char) * (strlen(cwd) + 8));
    temp = strcpycwd(temp, "OLDPWD=");
    temp = strcat(temp, cwd);

    for (i = 4; mysh->new_env[mysh->find_oldpwd][i] != '\0'; i++)
        mysh->new_env[mysh->find_oldpwd][i] = '\0';

    free(mysh->new_env[mysh->find_oldpwd]);
    mysh->new_env[mysh->find_oldpwd] = malloc(
    sizeof(char) * (strlen(cwd) + 8));

    mysh->new_env[mysh->find_oldpwd] = strcpycwd(
    mysh->new_env[mysh->find_oldpwd], temp);

    free(temp);
}

void execute_cd(Mysh *mysh, char **args)
{
    char *pwd = NULL;

    if (args[1] == NULL) {
        args[1] = mysh->home;
    } else if (strcmp(args[1], "-") == 0 && mysh->oldpwd != NULL) {
        args[1] = mysh->oldpwd;
    }
    pwd = getcwd(pwd, 0);
    mysh->oldpwd = malloc(sizeof(char *) * strlen(pwd));
    mysh->oldpwd = strcpy(mysh->oldpwd, pwd);
    if (chdir(args[1]) == -1 && args[1] != mysh->home) {
        printf("%s", args[1]);
        printf(": Not a directory.\n");
    } else {
        change_oldpwd(mysh, pwd);
        change_pwd(mysh);
    }
    free(pwd);
}
