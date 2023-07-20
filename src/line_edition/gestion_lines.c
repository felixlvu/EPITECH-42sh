/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** gestion_lines.c
*/

#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include "gestion_line.h"

void print_prompt(int ch)
{
    char* loc = NULL;
    char s[] = { 0xE2 ,0x86 ,0xB3 , 0, 0};

    if (isatty(0)) {
        if (ch == 1) {
            printf("\033[0;34m");
            fflush(stdout);
            printf("%s\n", getcwd(loc, 0));
            fflush(stdout);
            free(loc);
        }
        printf("\033[0;33m");
        fflush(stdout);
        printf("%s", s);
        fflush(stdout);
        printf("\033[0;37m");
        fflush(stdout);
    }
}

void suppr_char(line_history *line)
{
    int len = 0;

    for (int i = 0; line->history_line[i] != '\0'; i++) {
        len++;
    }
    for (int i = line->cursor_pos - 1; i < len; i++) {
        line->history_line[i] = line->history_line[i + 1];
    }
    line->history_line[len - 1] = '\0';
}

void print_line(line_history *line)
{
    printf("\x1B[K");
    fflush(stdout);
    printf("\033[s");
    fflush(stdout);
    printf("\x1B[1G");
    fflush(stdout);
    print_prompt(0);
    fflush(stdout);
    printf("%s", line->history_line);
    fflush(stdout);
    printf("\033[u");
    fflush(stdout);
}

void erase_char(line_history *line)
{
    if (line->cursor_pos == 1) {
        return;
    } else {
        suppr_char(line);
        line->cursor_pos--;
        printf("\x1B[1D");
        fflush(stdout);
    }
}
