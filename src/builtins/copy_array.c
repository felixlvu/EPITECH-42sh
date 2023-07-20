/*
** EPITECH PROJECT, 2022
** mysh
** File description:
** mysh
*/

#include "mym.h"

char **copy_array_remove(char **array, int remove_line)
{
    char **temp = NULL;
    int len_array = 0;
    int index = 0;

    for (len_array = 0 ; array[len_array] != NULL; len_array++);
    if (remove_line != 0)
        len_array = len_array - remove_line;
    temp = malloc(sizeof(char *) * (len_array + 1));

    for (index = 0; array[index] != NULL; index++) {
        temp[index] = malloc(sizeof(char) * strlen(array[index]) + 1);
        temp[index][strlen(array[index])] = '\0';
        temp[index] = strcpy(temp[index], array[index]);
        free(array[index]);
    }
    temp[index - 1] = NULL;
    free(array);

    return (temp);
}

char **copy_array_add(char **array, int add_line)
{
    char **temp = NULL;
    int len_array = 0;
    int index = 0;

    for (len_array = 0 ; array[len_array] != NULL; len_array++);
    if (add_line != 0)
        len_array = len_array + add_line;
    temp = malloc(sizeof(char *) * (len_array + 1));

    for (index = 0; array[index] != NULL; index++) {
        temp[index] = malloc(sizeof(char) * (strlen(array[index]) + 1));
        temp[index][strlen(array[index])] = '\0';
        temp[index] = strcpy(temp[index], array[index]);
        free(array[index]);
    }
    temp[index] = '\0';
    temp[index + 1] = NULL;
    free(array);

    return (temp);
}

char **copy_array(char **array)
{
    char **temp = NULL;
    int len_array = 0;
    int index = 0;

    for (len_array = 0 ; array[len_array] != NULL; len_array++);
    temp = malloc(sizeof(char *) * (len_array + 1));

    for (index = 0; array[index] != NULL; index++) {
        temp[index] = malloc(sizeof(char) * (strlen(array[index]) + 1));
        temp[index][strlen(array[index])] = '\0';
        temp[index] = strcpy(temp[index], array[index]);
        free(array[index]);
    }
    temp[index] = NULL;
    free(array);

    return (temp);
}
