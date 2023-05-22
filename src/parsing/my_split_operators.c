/*
** EPITECH PROJECT, 2022
** my_split_operators
** File description:
** c file for my split operators
*/

#include "shell.h"

const char operators[OPT_NUM][3] ={
    "&&",
    "||",
    ">>",
    "<<",
    ">",
    "<",
    "|",
    ";"
    };

int is_operator(char first, char second)
{
    for (int j = 0; j < OPT_NUM; j++) {
        if (first == operators[j][0] &&
        (!operators[j][1] || second == operators[j][1]))
            return ((operators[j][1]) ? 2 : 1);
    }
    return (0);
}

int update_size(char *arr, int *y, int i)
{
    int ret = is_operator(arr[i], arr[i + 1]);
    if (ret == 0)
        return (i);
    if (i > 0 && is_operator(arr[i - 1], arr[i]) == 0)
        (*y)++;
    if (arr[i + 1])
        (*y)++;
    if (ret == 2)
        return (i++);
    return (i);
}

int size(char **arr, int *y)
{
    int ret = 0;
    int len = 0;
    int x = 0;
    bool same = false;

    for (int j = 0; arr[j]; j++) {
        same = false;
        len = my_strlen(arr[j]);
        if (len > x)
            x = len;
        for (int a = 0; a < OPT_NUM; a++)
            same = (my_strcmp(operators[a], arr[j]) == 0) ? true : same;
        for (int i = 0; !same && arr[j][i]; i++)
            i = update_size(arr[j], y, i);
    }
    return (x);
}

void fill_new(char *arr, char **new, int *y)
{
    int x = 0;
    int ret = 0;

    for (int i = 0; arr[i]; i++, x++) {
        if (new[(*y)] && !new[(*y)][0])
            x = 0;
        if ((ret = is_operator(arr[i], arr[i + 1])) != 0)
            new[(*y)][x] = arr[i];
        if (ret == 2) {
            x++;
            i++;
            new[(*y)][x] = arr[i];
        }
        if (ret == 0)
            new[(*y)][x] = arr[i];
        if ((arr[i + 1] && (is_operator(arr[i + 1], arr[i + 2]) != 0 || (ret
        != 0 && is_operator(arr[i + 1], arr[i + 2]) == 0))) || !arr[i + 1])
            (*y)++;
    }
}

char **my_split_operators(char **arr)
{
    int y = my_arrlen(arr);
    int x = size(arr, &y);
    int a = 0;
    char **new = NULL;

    if (x == 0 || y == 0)
        return (NULL);
    new = my_arr_ini(x, y);
    if (!new)
        return (NULL);
    for (int j = 0; arr[j]; j++)
        fill_new(arr[j], new, &a);
    return (new);
}
