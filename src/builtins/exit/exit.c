/*
** EPITECH PROJECT, 2023
** exit
** File description:
** c file for exit
*/

#include "shell.h"

int my_exit(char **arg, node_t *node, history *history, int *fd)
{
    int length = my_arrlen(arg);

    if (length == 2 && (arg[1][0] >= '0' && arg[1][0] <= '9')
    && my_str_isnum(arg[1]) == 84) {
        my_puterror("exit: Badly formed number.\n");
        return (84);
    } else if (length > 2 || (length == 2 && my_str_isnum(arg[1]) == 84)) {
        my_puterror("exit: Expression Syntax.\n");
        return (84);
    }
    if (my_arrlen(arg) == 1)
        exit(0);
    else
        exit(my_getnbr(arg[1]));
}
