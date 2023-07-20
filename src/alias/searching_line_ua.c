/*
** EPITECH PROJECT, 2023
** 42sh_
** File description:
** searching_line_ua
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "mym.h"

int break_searching(char *buffer, char *args[], int i)
{
    if (strncmp(buffer + i, args[1], strlen(args[1])) == 0) {
        if (buffer[i + strlen(args[1])] == '=' &&
        (buffer[i - 1] == '\n' || buffer[i - 1] == '\0'))
            return 1;
    }
    return 0;
}

void search_line_editing(char *args[], int fd)
{
    char *buffer = NULL;
    struct stat buf;
    int i = 0;

    stat(".42rc", &buf);
    buffer = malloc(buf.st_size + 1);
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';

    for (; buffer[i] != '\0'; i++) {
        if (break_searching(buffer, args, i) == 1)
            break;
    }
    unalias_editing_rc(i, fd, buffer);
    free(buffer);
    close(fd);
}
