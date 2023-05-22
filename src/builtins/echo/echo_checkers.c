/*
** EPITECH PROJECT, 2023
** echo_checkers
** File description:
** function utils for command echo
*/

#include "shell.h"

bool check_echo_flag(char **arg)
{
    if (my_strcmp(arg[1], "-n") == 0)
        return (true);
    return (false);
}

void cond_colons(char to_check, int *nb_semicol, int *nb_col)
{
    if (to_check == '\'')
        (*nb_semicol)++;
    if (to_check == '"')
        (*nb_col)++;
}

bool check_colons(char **arg, bool flag_n)
{
    int i = (flag_n) ? 2 : 1;
    int nb_col = 0;
    int nb_semicol = 0;

    while (arg[i]) {
        for (int j = 0; arg[i][j]; j++)
            cond_colons(arg[i][j], &nb_semicol, &nb_col);
        i++;
    }
    if (nb_col % 2 != 0) {
        my_puterror("Unmatched '\"'.\n");
        return (false);
    }
    if (nb_semicol % 2 != 0) {
        my_puterror("Unmatched '\''.\n");
        return (false);
    }
    return (true);
}
