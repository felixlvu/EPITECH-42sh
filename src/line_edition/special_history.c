/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** special_history
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gestion_line.h"

line_history *add_node(line_history *history)
{
    line_history *new_node = malloc(sizeof(line_history));

    if (new_node == NULL)
        return NULL;
    new_node->history_line[0] = '\0';
    new_node->cursor_pos = 1;
    new_node->prev = NULL;
    new_node->next = history;
    return new_node;
}

void decal_cursor(line_history *line)
{
    int i = 0;

    for (; line->history_line[i] != '\0'; i++) {
        printf("\x1B[1D");
        fflush(stdout);
    }
    for (int j = 0; j < i; j++) {
        printf("\x1B[1C");
        fflush(stdout);
    }
}

line_history *arrow_up(line_history *line, line_history *history)
{
    if (history == NULL || history->next == NULL) {
        return history;
    } else {
        strcpy(line->history_line, history->history_line);
        history = history->next;
        return history;
    }
}

line_history *arrow_down(line_history *line, line_history *history)
{
    if (history == NULL || history->prev == NULL) {
        return line;
    } else {
        strcpy(line->history_line, history->history_line);
        history = history->prev;
        return history;
    }
}
