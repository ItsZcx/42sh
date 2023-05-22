/*
** EPITECH PROJECT, 2023
** operator
** File description:
** c file for operator
*/

#include "shell.h"

int find_and_or(char **arr)
{
    int last = -1;

    for (int j = 0; arr[j]; j++) {
        if (my_strcmp(arr[j], "&&") == 0 || my_strcmp(arr[j], "||") == 0)
            last = j;
    }
    return (last);
}

int find_redirection(char **arr)
{
    int last = -1;

    for (int j = 0; arr[j]; j++) {
        if (my_strcmp(arr[j], ">") == 0 || my_strcmp(arr[j], "<") == 0
        || my_strcmp(arr[j], ">>") == 0 || my_strcmp(arr[j], "<<") == 0
        || my_strcmp(arr[j], "|") == 0)
            last = j;
    }
    return (last);
}

int find_semi(char **arr)
{
    int last = -1;

    for (int j = 0; arr[j]; j++) {
        if (my_strcmp(arr[j], ";") == 0)
            last = j;
    }
    return (last);
}

bool are_operators(char **arr)
{
    for (int j = 0; arr && arr[j]; j++) {
        if (my_strcmp(arr[j], "&&") == 0 || my_strcmp(arr[j], "||") == 0
        || my_strcmp(arr[j], ">") == 0 || my_strcmp(arr[j], "<") == 0
        || my_strcmp(arr[j], ">>") == 0 || my_strcmp(arr[j], "<<") == 0
        || my_strcmp(arr[j], "|") == 0 || my_strcmp(arr[j], ";") == 0)
            return (true);
    }
    return (false);
}
