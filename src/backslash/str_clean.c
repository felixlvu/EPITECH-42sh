/*
** EPITECH PROJECT, 2022
** 42sh
** File description:
** str_clean
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *delete_tab(char *buff)
{
    for (int i = 0; buff[i] != '\0' ; i++) {
        if (buff[i] == '\t') {
            buff[i] = ' ';
        }
    }
    return buff;
}

char *end_buff(char *str, char *buff, int j, int compt)
{
    if (str[compt + 1] != ' ' && str[compt + 1] != '\t') {
        buff[j] = str[compt + 1];
        buff[j + 1] = '\0';
    } else {
        buff[j] = '\0';
    }
    return buff;
}

char *str_clean(char *str)
{
    char *buff = NULL;
    int compt = 0;
    int j = 0;

    buff = malloc(sizeof(char) * (strlen(str) + 1));
    while (str[compt] == ' ' || str[compt] == '\t') {
        compt++;
    }
    for (int i = compt ; str[i + 1] != '\0' ; i++) {
        if ((str[i] != ' ' && str[i] != '\t') ||
        (str[i + 1] != ' ' && str[i + 1] != '\t')) {
            buff[j] = str[i];
            j++;
        }
        compt = i;
    }
    buff = end_buff(str, buff, j, compt);
    buff = delete_tab(buff);
    return buff;
}

char *strcleantok(char *str)
{
    char *token = NULL;
    int i = 0;
    char **test = NULL;

    test = malloc(sizeof(char *) * (strlen(str) + 1));
    token = strtok(str, " \t");
    while (token != NULL) {
        test[i] = token;
        i++;
        token = strtok(NULL, " \t");
    }
    test[i] = NULL;

    return test[0];
}
