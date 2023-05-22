/*
** EPITECH PROJECT, 2023
** which_operator
** File description:
** c file for which operator
*/

#include "shell.h"

const char operators1[OPT_NUM][3] = {
    ";",
    "|",
    ">",
    "<",
    ">>",
    "<<",
    "&&",
    "||"
    };

int which_operator(char *str)
{
    for (int j = 0; j < OPT_NUM; j++) {
        if (my_strcmp(operators1[j], str) == 0)
            return (j);
    }
    return (0);
}
