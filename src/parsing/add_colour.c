/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** add_color
*/

#include "shell.h"

bool cmd_uses_colors(char **cmd)
{
    char *arr[4] = {"ls", "grep", "diff", NULL};

    for (int index = 0; index < 4; index++) {
        if (my_strcmp(cmd[0], arr[index]) == 0)
            return (true);
    }
    return (false);
}

char **add_colour(char **arr)
{
    int size = my_arrlen(arr);
    char **new_arr = malloc(sizeof(char *) * (size + 2));

    if (cmd_uses_colors(arr) == false) {
        free(new_arr);
        return (arr);
    }
    if (!new_arr)
        return (NULL);
    for (int index = 0; arr[index]; index++)
        new_arr[index] = my_strdup(arr[index]);
    new_arr[size] = my_strdup("--color=auto");
    new_arr[size + 1] = NULL;
    return (new_arr);
}
