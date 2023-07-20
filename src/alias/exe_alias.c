/*
** EPITECH PROJECT, 2023
** 42sh_
** File description:
** exe_alias
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "mym.h"

int break_searching_for_exe(char *buffer, char *args[], int i)
{
    if (strncmp(buffer + i, args[0], strlen(args[0])) == 0) {
        if (buffer[i + strlen(args[0])] == '=' &&
        (buffer[i - 1] == '\n' || buffer[i - 1] == '\0')) {
            return 1;
        }
    }
    return 0;
}

char *read_rc_exe_alias(int fd, char *buffer)
{
    struct stat buf;

    fd = check_alias_exists();
    stat(".42rc", &buf);
    buffer = malloc(buf.st_size + 1);
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    return buffer;
}

char *get_cmd_exe_alias(char *buffer, char *result, int i)
{
    int k = 0;
    int bso = 0;

    for (; buffer[i] != '='; i++);
    for (k = i + 1; buffer[k] != '\n'; k++);
    result = malloc(sizeof(char) * (k - i));
    bso = k - i;
    i++;
    for (int j = 0; buffer[i] != '\n'; i++, j++)
        result[j] = buffer[i];
    result[bso - 1] = '\0';
    return result;
}

void exe_alias(char **args)
{
    int fd = 0;
    char *buffer = NULL;
    char *result = NULL;
    int i = 0;

    buffer = read_rc_exe_alias(fd, buffer);
    for (; buffer[i] != '\0'; i++) {
        if (break_searching_for_exe(buffer, args, i) == 1)
            break;
    }
    if (i == (int) strlen(buffer))
        return;
    result = get_cmd_exe_alias(buffer, result, i);
    execvp(result, args);
    free(buffer);
    free(result);
    close(fd);
}
