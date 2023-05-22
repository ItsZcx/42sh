/*
** EPITECH PROJECT, 2023
** env
** File description:
** c file for env
*/

#include "shell.h"

int env(char **arg, node_t *node, history *history, int *fd)
{
    while (node) {
        dprintf(fd[2], "%s\n", node->env);
        node = node->next;
    }
    return (0);
}
