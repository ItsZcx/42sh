/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** new_arr_len
*/

#include "shell.h"

int num_length(char *cmd, history *end, int num)
{
    int length = 0;
    char **temp = NULL;

    while (end) {
        if (end->pos == num) {
            temp = my_split_operators(my_new_split(end->cmd, " \t"));
            length = my_arrlen(temp);
            free_arr(temp);
            return (length);
        }
        end = end->prev;
    }
    return (0);
}

int hist_length(char *cmd, history *end, int length)
{
    if ((cmd[1] < 47 || cmd[1] > 58) && cmd[1]
        != '-' && cmd[1] != '!' && cmd[1] != '#') {
        length = hist_substitution_length(cmd, end);
        return (length);
    }
    if (cmd[1] == '!') {
        length = last_hist_substitution_length(cmd, end);
        return (length);
    }
    if (cmd[1] == '#') {
        length = length;
        return (length);
    }
    if (my_str_isnum(cut_str_start(cmd, 1)) != 84
        || my_str_isnum(cut_str_start(cmd, 2)) != 84) {
        length = hist_num_substitution_length(cmd, end);
        return (length);
    }
    return (0);
}

int new_arr_len(char **arr, history *end)
{
    history *node = end;
    int index = 0;
    int length = 0;
    char **temp = NULL;

    if (arr == NULL)
        return (0);
    length = my_arrlen(arr);
    while (arr[index]) {
        if (arr[index][0] == '!')
            length += hist_length(arr[index], node, length) - 1;
        index++;
    }
    return (length);
}
