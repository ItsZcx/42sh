/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-minishell2-joan-pau.merida-ruiz [WSL: Ubuntu]
** File description:
** cut_str_start
*/

#include "my_string.h"

char *cut_str_start(char *to_cut, int chars_to_cut)
{
    int pos = 0;
    char *cut = malloc(sizeof(char) * (my_strlen(to_cut) - chars_to_cut + 1));

    while (to_cut[chars_to_cut]) {
        cut[pos] = to_cut[chars_to_cut];
        chars_to_cut++;
        pos++;
    }
    cut[pos] = '\0';
    return (cut);
}
