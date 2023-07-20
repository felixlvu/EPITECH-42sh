/*
** EPITECH PROJECT, 2023
** 42sh_
** File description:
** unalias
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "mym.h"

char *strcpy_k(char *dest, char *src, int k)
{
    int i = 0;
    int len_dest = 0;

    for (; len_dest != k; len_dest++);
    dest = malloc(sizeof(char) * (len_dest + 1));
    for (; i != k; i++)
        dest[i] = src[i];
    dest[i] = '\0';
    return (dest);
}

char *strcpy_line_bn(char *dest, char *src)
{
    int i = 0;
    int len_dest = 0;

    for (; src[i] != '\n'; i++);
    len_dest = i;
    for (; src[len_dest] != '\0'; len_dest++);
    len_dest -= i;
    dest = malloc(sizeof(char) * (len_dest + 1));
    len_dest = 0;
    i++;
    for (; src[len_dest + i] != '\0'; len_dest++)
        dest[len_dest] = src[len_dest + i];
    dest[len_dest] = '\0';
    return (dest);
}

void unalias_editing_rc(int i, int fd, char *buffer)
{
    char *temp1 = NULL;
    char *temp2 = NULL;
    char *temp3 = NULL;

    if (i != (int) strlen(buffer)) {
        temp1 = strcpy_k(temp1, buffer, i);
        temp2 = strcpy_line_bn(temp2, buffer + i);
        temp3 = malloc(strlen(temp1) + strlen(temp2) + 1);
        strcpy(temp3, temp1);
        strcat(temp3, temp2);
        truncate(".42rc", 0);
        lseek(fd, 0, SEEK_SET);
        write(fd, temp3, strlen(temp3));
    }
}

void unalias(char *args[])
{
    int fd = 0;

    if (args[1] == NULL || args[2] != NULL) {
        return;
    } else {
        fd = check_alias_exists();
        search_line_editing(args, fd);
    }
}
