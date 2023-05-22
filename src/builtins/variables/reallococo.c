/*
** EPITECH PROJECT, 2023
** reallococo
** File description:
** my_realloc funtion
*/

#include "shell.h"

void fill_ret_realloc(char *ret, char *str,
size_t new_size, size_t size)
{
    for (size_t i = 0; i < new_size; i++) {
        if (i < size)
            ret[i] = str[i];
        else
            ret[i] = '\0';
    }
}

char *my_reallococo(char *str, size_t new_size)
{
    char *ret = NULL;
    size_t size = 0;
    if (!str) {
        ret = malloc(sizeof(char) * new_size);
        return (ret);
    }
    size = my_strlen(str);
    if (new_size == 0) {
        free(str);
        return (NULL);
    }
    if (new_size <= size)
        return (str);
    ret = malloc(sizeof(char) * new_size);
    fill_ret_realloc(ret, str, new_size, size);
    if (!ret)
        return (NULL);
    free(str);
    return (ret);
}
