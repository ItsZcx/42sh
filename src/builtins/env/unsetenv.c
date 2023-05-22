/*
** EPITECH PROJECT, 2023
** unsetenv
** File description:
** c file for unsetenv
*/

#include "shell.h"

void remove_node(node_t *node, node_t *prev)
{
    if (prev)
        prev->next = node->next;
    node = NULL;
}

int my_unsetenv(char **arg, node_t *node, history *history, int *fd)
{
    node_t *prev = NULL;

    if (my_arrlen(arg) != 2)
        return (84);
    while (node) {
        if (my_strcmp(node->var[0], arg[1]) == 0) {
            remove_node(node, prev);
            break;
        }
        prev = node;
        node = node->next;
    }
    return (0);
}
