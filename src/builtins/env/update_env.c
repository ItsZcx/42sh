/*
** EPITECH PROJECT, 2023
** update_env
** File description:
** c file for update env
*/

#include "shell.h"

int update_env(char *var, char *value, node_t *node)
{
    bool changed = false;

    if (!var || !value)
        return (84);
    while (node) {
        if (my_strcmp(node->var[0], var) == 0) {
            change_env(node, value);
            changed = true;
            break;
        }
        node = node->next;
    }
    if (!changed)
        return (84);
    else
        return (0);
}
