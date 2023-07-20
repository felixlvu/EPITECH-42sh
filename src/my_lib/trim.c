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

void trim(char *str)
{
    char *start, *end;
    int len = strlen(str);

    for (start = str; *start && isspace(*start); ++start);

    for (end = str + len - 1; end > start && isspace(*end); --end);

    *(end + 1) = '\0';

    memmove(str, start, end - start + 2);
}
