/*
** EPITECH PROJECT, 2023
** echo
** File description:
** file for echo
*/

#include "shell.h"

// 34 is "
// 39 is '
// 92 is backlash

void display_chars(char **arg, int i, int len_arg, int *fd)
{
    bool is_back = false;

    for (int j = 0; arg[i][j]; j++) {
        while (arg[i][j] == '\'' || arg[i][j] == '"')
            j++;
        if (!arg[i][j])
            break;
        if (arg[i][j] == '\\' && arg[i][j + 1]) {
            j++;
            is_back = true;
        }
        if (arg[i][j] == '\\' && arg[i][j + 1] && is_backlash(arg[i][j + 1])) {
            j++;
            display_backlash(arg[i][j], fd);
        } else {
            write(fd[2], &arg[i][j], 1);
        }
    }
}

void display_chars_collons(char **arg, int i, int len_arg, int *fd)
{
    for (int j = 0; arg[i][j]; j++) {
        while (arg[i][j] == '\'' || arg[i][j] == '"')
            j++;
        if (!arg[i][j])
            break;
        if (arg[i][j + 1] && arg[i][j] == '\\' && is_backlash(arg[i][j + 1])) {
            j++;
            display_backlash(arg[i][j], fd);
        } else
            write(fd[2], &arg[i][j], 1);
    }
}

void display_echo(char **arg, bool flag_n, int len_arg, int *fd)
{
    int i = 1;

    if (flag_n)
        i = 2;
    while (arg[i]) {
        if ((arg[i][0] == '"' || arg[i][0] == '\'')
        && ((arg[i][my_strlen(arg[i]) - 1] == '"' ||
        arg[i][my_strlen(arg[i]) - 1] == '\'')))
            display_chars_collons(arg, i, len_arg, fd);
        else
            display_chars(arg, i, len_arg, fd);
        if (i != (len_arg - 1))
            write(fd[2], " ", 1);
        i++;
    }
    if (!flag_n)
        write(fd[2], "\n", 1);
}

int my_echo(char **arg, node_t *node, history *history, int *fd)
{
    bool flag_n = false;
    int len_arg = my_arrlen(arg);
    char *var = NULL;

    if (len_arg == 1) {
        write(fd[2], "\n", 1);
        return (0);
    }
    flag_n = check_echo_flag(arg);
    if (!check_colons(arg, flag_n))
        return (84);
    display_echo(arg, flag_n, len_arg, fd);
    return (0);
}
