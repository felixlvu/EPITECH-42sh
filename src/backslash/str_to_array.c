/*
** EPITECH PROJECT, 2023
** clean string
** File description:
** display the different word of a string separated by spaces
*/

#include <unistd.h>
#include <stdlib.h>

static int get_number_word(char const *str, char delim)
{
    int size = 1;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == delim) {
            size += 1;
        }
    }
    return (size);
}

static int get_word_size(char const *str, char delim)
{
    int size = 0;

    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] == delim) {
            return (size);
        }
        size += 1;
    }
    return (size);
}

static char *get_word(char const *str, int index, char delim)
{
    int index_new_word = 0;
    char *new_word = NULL;
    int size = 0;

    size = get_word_size(&str[index], delim);
    new_word = malloc(sizeof(char) * (size + 1));
    if (new_word == NULL) {
        return (NULL);
    }
    while (str[index] != delim && str[index] != '\0') {
        new_word[index_new_word] = str[index];
        new_word[index_new_word + 1] = '\0';
        index += 1;
        index_new_word += 1;
    }
    return (new_word);
}

char **str_to_array(char const *str, char delim)
{
    int size = 0;
    char **word_array = NULL;
    int array_index = 0;

    size = get_number_word(str, delim);
    word_array = malloc(sizeof(char*) * (size + 2));
    if (word_array == NULL) {
        return (NULL);
    }
    for (int index = 0; str[index] != '\0'; index++) {
        if (str[index] != delim) {
            word_array[array_index] = get_word(str, index, delim);
            array_index += 1;
            index += get_word_size(&str[index], delim) - 1;
        }
    }
    word_array[array_index] = NULL;
    return (word_array);
}
