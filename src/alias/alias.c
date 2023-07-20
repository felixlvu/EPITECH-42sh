/*
** EPITECH PROJECT, 2023
** 42sh_
** File description:
** alias
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "mym.h"

int check_alias_exists(void)
{
    int fd = open(".42rc", O_RDWR);
    if (fd == -1) {
        fd = open(".42rc", O_CREAT | O_WRONLY, 0644);
    }
    return fd;
}

void read_and_write_alias(char *alias_name, char *alias_command, int fd)
{
    char *buffer = NULL;
    struct stat buf;

    stat(".42rc", &buf);
    buffer = malloc(buf.st_size + 1);
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    buffer = realloc(buffer, buf.st_size +
    strlen(alias_name) + strlen(alias_command) + 4);
    strcat(buffer, alias_name);
    strcat(buffer, "=");
    strcat(buffer, alias_command);
    strcat(buffer, "\n");
    lseek(fd, 0, SEEK_SET);
    write(fd, buffer, strlen(buffer));
    free(buffer);
    close(fd);
    return;
}

char *fill_output_str(char *output, const char *input)
{
    char *line = NULL;
    char* equalSign = NULL;

    line = strtok(strdup(input), "\n");
    while (line != NULL) {
        equalSign = strchr(line, '=');
        if (equalSign != NULL) {
            *equalSign = '\0';
            strcat(output, line);
            strcat(output, "\t");
            strcat(output, equalSign + 1);
            strcat(output, "\n");
        }
        line = strtok(NULL, "\n");
    }
    free(line);
    return output;
}

void alias(char *args[])
{
    int fd;

    if (args[1] == NULL)
        simple_alias();
    else if (args[2] == NULL || args[3] != NULL)
        return;
    else {
        fd = check_alias_exists();
        read_and_write_alias(args[1], args[2], fd);
    }
}
