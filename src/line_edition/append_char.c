/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** append_char.c
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stddef.h>
#include "gestion_line.h"

char* n_append(char* string, int pos, char elm)
{
    int len = 0;

    for (int i = 0; string[i] != '\0'; i++) {
        len++;
    }
    for (int i = len; i >= pos - 1; i--) {
        if (i == pos - 1)
            string[i] = elm;
        else
            string[i] = string[i - 1];
    }
    string[pos - 1] = elm;
    string[len + 1] = '\0';
    return (string);
}

void arrow_right(line_history *line)
{
    if ((int)strlen(line->history_line) < line->cursor_pos) {
        return;
    } else {
        printf("\x1B[1C");
        fflush(stdout);
        line->cursor_pos++;
    }
}

void arrow_left(line_history *line)
{
    if (line->cursor_pos - 1 == 0) {
        return;
    } else {
        printf("\x1B[1D");
        fflush(stdout);
        line->cursor_pos--;
    }
}
