/*
** EPITECH PROJECT, 2023
** search_env_variables
** File description:
** function utils to get env variables
*/

#include "shell.h"

char *get_var_value_env(node_t *node)
{
    char *var_value = NULL;

    if (node->var[1] && node->var[1][0] != '$') {
        var_value = my_malloc_ini(my_strlen(node->var[1]));
        var_value = my_strcpy(var_value, node->var[1]);
    }
    return (var_value);
}

char *search_env_var(node_t *node, char *var, bool *exists)
{
    char *var_value = NULL;

    while (node) {
        if (my_strcmp(node->var[0], var) == 0) {
            (*exists) = true;
            var_value = get_var_value_env(node);
        }
        node = node->next;
    }
    return (var_value);
}
