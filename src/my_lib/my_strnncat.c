/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

char* my_strnncat(char* dest, const char* src, size_t n, size_t m)
{
    int i = 0;

    for (i = 0; src[i + n] != '\0'; i++) {
        dest[i + m] = src[i + n];
    }
    dest[i + m] = '\0';
    return dest;
}
