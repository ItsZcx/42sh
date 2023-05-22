/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** do_substitutions
*/

#include "shell.h"

char **dup_substitution(history_ints *ints, char **new_arr, char **arr)
{
    char **temp = dup_array(new_arr, ints->h_index);

    temp = my_split_operators(my_new_split(my_arr_to_str(temp), " \t"));
    return (temp);
}

char **num_substitution(char *cmd, history *end, int num)
{
    char **temp = NULL;

    while (end) {
        if (end->pos == num && num != 0) {
            temp = my_split_operators(my_new_split(end->cmd, " \t"));
            return (temp);
        }
        end = end->prev;
    }
    return (NULL);
}

char **hist_num_substitution(char *cmd, history *end)
{
    int num = 0;
    char **temp = NULL;

    if (end && end->prev) {
        if (cmd[1] == '-')
            num = end->prev->pos - my_getnbr(cut_str_start(cmd, 2)) + 1;
        else
            num = my_getnbr(cut_str_start(cmd, 1));
        temp = num_substitution(cmd, end, num);
    }
    return (temp);
}

char **last_hist_substitution(char *cmd, history *end)
{
    char **temp = NULL;

    if (!end)
        return (NULL);
    while (end->cmd == NULL && end->prev != NULL)
        end = end->prev;
    if (end->cmd) {
        temp = my_split_operators(my_new_split(end->cmd, " \t"));
        return (temp);
    }
    return (NULL);
}

char **hist_substitution(char *cmd, history *end)
{
    char **temp = NULL;

    while (end) {
        if (end->cmd)
            temp = my_split_operators(my_new_split(end->cmd, " \t"));
        if (end->cmd && my_strcmp(my_strcat2("!", temp[0]), cmd) == 0)
            return (temp);
        end = end->prev;
    }
    free_arr(temp);
    return (NULL);
}
