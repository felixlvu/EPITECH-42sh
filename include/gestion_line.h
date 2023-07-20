/*
** EPITECH PROJECT, 2023
** B-PSU-200-TLS-2-1-42sh-paul.arbez
** File description:
** gestion_line.h
*/
#ifndef GESTION_LINE_H_
    #define GESTION_LINE_H_

    #include "../include/mym.h"

    typedef struct line_history {
        char history_line[4096];
        int cursor_pos;
        struct line_history *prev;
        struct line_history *next;
    }line_history;
char* n_append(char* string, int pos, char elm);
void print_prompt(int ch);
void arrow_left(line_history *line);
void arrow_right(line_history *line);
line_history *def_history(void);
line_history *put_in_history(line_history *history, line_history *new_elm);
void print_history(line_history *history);
void suppr_char(line_history *line);
void print_welcome_msg(void);
void clear_window(void);
void print_line(line_history *line);
void erase_char(line_history *line);
void free_history(line_history *history);
void def_term(void);
line_history *arrow_up(line_history *line, line_history *history);
line_history *arrow_down(line_history *line, line_history *history);
line_history *add_node(line_history *history);
line_history *get_line(line_history *history, Mysh *my_sh);

#endif /*GESTION_LINE_H_*/
