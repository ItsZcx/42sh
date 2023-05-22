/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** cmd_finder
*/

#include "shell.h"

bool do_normal_substitution(history_ints *ints, char **arr)
{
    if ((arr[ints->a_index][1] < 47 || arr[ints->a_index][1] > 58) &&
        arr[ints->a_index][1] != '-' && arr[ints->a_index][1] != '!'
        && arr[ints->a_index][1] != '#')
        return (true);
    return (false);
}

bool do_last_substitution(history_ints *ints, char **arr)
{
    if (arr[ints->a_index][1] == '!')
        return (true);
    return (false);
}

bool do_dup_substitution(history_ints *ints, char **arr)
{
    if (arr[ints->a_index][1] == '#')
        return (true);
    return (false);
}

bool do_num_substitution(history_ints *ints, char **arr)
{
    if (my_str_isnum(cut_str_start(arr[ints->a_index], 1)) != 84
    || my_str_isnum(cut_str_start(arr[ints->a_index], 2)) != 84)
        return (true);
    return (false);
}

char **cmd_finder(history *end, history_ints *ints, char **new_arr, char **arr)
{
    bool enter = false;
    char **temp = NULL;

    if (do_normal_substitution(ints, arr) == true) {
        temp = hist_substitution(arr[ints->a_index], end);
        return (temp);
    }
    if (do_last_substitution(ints, arr) == true) {
        temp = last_hist_substitution(arr[ints->a_index], end);
        return (temp);
    }
    if (do_dup_substitution(ints, arr) == true) {
        temp = dup_substitution(ints, new_arr, arr);
        return (temp);
    }
    if (do_num_substitution(ints, arr) == true) {
        temp = hist_num_substitution(arr[ints->a_index], end);
        return (temp);
    }
    return (NULL);
}
