/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** main
*/

#include <stdlib.h>
#include <stddef.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include "../include/mym.h"
#include "gestion_line.h"
#include <curses.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <stdarg.h>

line_history *arrow_key(line_history * line, line_history *new_elm)
{
    int c = 0;

    c = getchar();
    switch (c) {
        case 67:
            arrow_right(new_elm);
            break;
        case 68:
            arrow_left(new_elm);
            break;
        case 66:
            line = arrow_down(new_elm, line);
            break;
        case 65:
            line = arrow_up(new_elm, line);
            break;
    }
    return line;
}

line_history *get_key(line_history *line, int elm, line_history *new_elm)
{
    int c = 0;

    if (elm == 12) {
        clear_window();
        return new_elm;
    }
    if (elm == 127) {
        erase_char(new_elm);
        return new_elm;
    }
    c = getchar();
    switch (c) {
        case 91:
            line = arrow_key(line, new_elm);
            break;
    }
    return line;
}

void append_char(int c , line_history *line_info)
{
    char element = (char)c;

    n_append(line_info->history_line, line_info->cursor_pos, element);
    line_info->cursor_pos++;
    fflush(stdout);
    printf("\x1B[1C");
    fflush(stdout);
}

line_history *get_line(line_history *history, Mysh *my_sh)
{
    int c;
    line_history *tmp = NULL;
    line_history *new_elm = NULL;

    new_elm = def_history(); tmp = history;
    while ((c = getchar()) != EOF && c != '\n'){
        if (c == 4) {
            my_sh->exit = 1;
            return new_elm;
        }
        if (c == 27 || c == 127 || c == 12) {
            tmp = get_key(tmp, c, new_elm);
        } else {
            append_char(c, new_elm);
            fflush(stdout);
        }
        print_line(new_elm);
    }
    printf("\n");
    return (new_elm);
}
