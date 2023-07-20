/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"
#include <stddef.h>
#include <stdlib.h>
#include <string.h>

struct poubelle {
    char **return_str;
    int index_str;
    int i;
};

int compteur_separator(int compteur_sep, char *str, char separator)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == separator || str[i] == '\n')
            compteur_sep++;
    }
    return compteur_sep;
}

int malloc_return_str(struct poubelle *p, char *str, char separator, int i)
{
    int malloc_count = 0;

    for (; str[p->index_str] != '\n' &&
    str[p->index_str] != separator; p->index_str++)
        malloc_count++;
    p->index_str++;
    p->return_str[i] = malloc(sizeof(char) * malloc_count + 1);
    return p->index_str;
}

char **str_to_word_array (char *str, char separator)
{
    struct poubelle *p;
    int compteur_sep = 0;

    p = malloc(sizeof(struct poubelle));
    compteur_sep = compteur_separator(compteur_sep, str, separator);
    p->index_str = 0;
    p->return_str = malloc(sizeof(char*) * (compteur_sep + 1));
    for (int i = 0; i != compteur_sep; i++) {
        int k = p->index_str;
        int j = 0;
        malloc_return_str(p, str, separator, i);
        for (j = 0; str[k] != '\n' && str[k] != separator; k++) {
            p->return_str[i][j] = str[k];
            j++;
        }
        p->return_str[i][j] = '\0';
    }
    p->return_str[compteur_sep] = NULL;
    return p->return_str;
}
