/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** history.c
*/

#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "gestion_line.h"

void print_history(line_history *history)
{
    line_history *tmp = history;
    int i = 1;

    while (tmp->next != NULL) {
        tmp = tmp->next;
    }
    while (tmp != NULL) {
        printf("   %d   ", i++);
        printf("%s\n", tmp->history_line);
        tmp = tmp->prev;
    }
}

line_history *def_history(void)
{
    line_history *history = malloc(sizeof(line_history));

    if (history == NULL)
        return (NULL);
    history->history_line[0] = '\0';
    history->cursor_pos = 1;
    history->prev = NULL;
    history->next = NULL;
    return (history);
}

line_history *add_to_history(line_history *new_li, line_history *history)
{
    new_li->prev = NULL;
    new_li->next = history;
    history->prev = new_li;

    while (history->next != NULL) {
        history = history->next;
    }
    return (new_li);
}

void parcour_history(char *line, line_history *history)
{
    line_history *tmp = history;
    int i = 0;
    int len = 0;

    len = strlen(line);
    for (; line[i] != '\0'; i++) {
        line[i] = line[i + 1];
    }
    while (tmp->next != NULL) {
        if (strncmp(tmp->history_line, line, len - 1) == 0) {
            line = tmp->history_line;
            return;
        }
        tmp = tmp->next;
    }
    printf("%s: Event not found\n", line);
}

line_history *put_in_history(line_history *history, line_history *new_elm)
{

    if (new_elm->history_line[0] == '!') {
        parcour_history(new_elm->history_line, history);
        return history;
    }
    if (strncmp(new_elm->history_line, "history", 7) == 0) {
        history = add_to_history(new_elm, history);
        print_history(history);
        return history;
    }
    history = add_to_history(new_elm, history);
    return history;
}
