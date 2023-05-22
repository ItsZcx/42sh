/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** substitution_length
*/

#include "shell.h"

int hist_num_substitution_length(char *cmd, history *end)
{
    int num = 0;
    int length = 0;

    if (end != NULL) {
        if (cmd[1] == '-')
            num = end->pos - my_getnbr(cut_str_start(cmd, 2)) + 1;
        else
            num = my_getnbr(cut_str_start(cmd, 1));
        length = num_length(cmd, end, num);
    }
    return (length);
}

int last_hist_substitution_length(char *cmd, history *end)
{
    int length = 0;
    char **temp = NULL;

    if (!end)
        return (0);
    while (end->cmd == NULL)
        end = end->prev;
    if (end->cmd) {
        temp = my_split_operators(my_new_split(end->cmd, " \t"));
        length = my_arrlen(temp);
        free_arr(temp);
        return (length);
    }
    return (0);
}

int hist_substitution_length(char *cmd, history *end)
{
    int length = 0;
    char **temp = NULL;

    while (end) {
        if (end->cmd)
            temp = my_split_operators(my_new_split(end->cmd, " \t"));
        if (end->cmd && my_strcmp(my_strcat2("!", temp[0]), cmd) == 0) {
            length = my_arrlen(temp);
            free_arr(temp);
            return (length);
        }
        end = end->prev;
    }
    return (0);
}
