/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** dup_array
*/

#include "shell.h"

char **dup_array(char **arr, int size)
{
    int pos = 0;
    int num = 0;
    char **result = NULL;

    for (int i = 0; my_strcmp(arr[i], "!#") != 0 && i < size; i++)
        num++;
    result = malloc(sizeof(char *) * (num + 1));
    if (!result || !arr)
        return (NULL);
    while (pos < num) {
        result[pos] = my_strdup(arr[pos]);
        pos++;
    }
    result[pos] = NULL;
    return (result);
}
