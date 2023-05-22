/*
** EPITECH PROJECT, 2023
** prompt
** File description:
** c file for prompt
*/

#include "shell.h"

void prompt(void)
{
    char *cwd = getcwd(NULL, 0);
    char **arr = NULL;

    write(1, "\033[1m\033[32m→ \033[1m\033[34m", 22);
    if (cwd) {
        arr = my_new_split(cwd, "/");
        if (arr && my_arrlen(arr) > 1) {
            my_putstr(arr[my_arrlen(arr) - 1]);
            free_arr(arr);
        } else
            my_putstr(cwd);
        free(cwd);
    }
    write(1, "\033[1m\033[033m ł \033[0m", 18);
}
