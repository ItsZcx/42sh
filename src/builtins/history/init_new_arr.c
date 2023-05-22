/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** init_new_arr
*/

#include "shell.h"

char **init_new_arr(history_ints *ints)
{
    char **new_arr = malloc(sizeof(char *) * (ints->length + 1));

    if (!new_arr || !ints)
        return (NULL);
    for (int index = 0; index < ints->length + 1; index++)
        new_arr[index] = NULL;
    return (new_arr);
}
