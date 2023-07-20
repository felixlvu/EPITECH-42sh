/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** special_key.c
*/

#include <string.h>
#include <curses.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#include <stdarg.h>
#include "gestion_line.h"

void clear_window(void)
{
    printf("\x1B[2J");
    fflush(stdout);
    printf("\x1B[H");
    fflush(stdout);
    print_prompt(1);
}

void free_history(line_history *history)
{
    line_history *tmp = history;

    while (tmp->next != NULL && tmp->prev != NULL) {
        tmp = tmp->next;
        free(tmp->prev);
    }
    free(tmp);
}

void def_term(void)
{
    struct termios *line = NULL;

    line = malloc(sizeof(struct termios));
    tcgetattr(STDIN_FILENO, line);
    line->c_lflag &= ~(ECHO | ICANON);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, line);
    free(line);
}
