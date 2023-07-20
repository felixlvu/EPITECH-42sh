/*
** EPITECH PROJECT, 2023
** 42sh_
** File description:
** alias_list
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>
#include <string.h>
#include "mym.h"

char* format_string(const char* input)
{
    int numLines = 1;
    char *output = NULL;

    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            numLines++;
        }
    }
    output = malloc(sizeof(char) * (strlen(input) + (numLines * 6) + 1));
    output[0] = '\0';
    output = fill_output_str(output, input);
    return output;
}

void simple_alias(void)
{
    int fd = 0;
    char *buffer = NULL;
    struct stat buf;

    fd = check_alias_exists();
    stat(".42rc", &buf);
    buffer = malloc(buf.st_size + 1);
    read(fd, buffer, buf.st_size);
    buffer[buf.st_size] = '\0';
    printf("%s", format_string(buffer));
    free(buffer);
}
