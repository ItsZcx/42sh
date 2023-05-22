/*
** EPITECH PROJECT, 2023
** setenv
** File description:
** c file for setenv
*/

#include "shell.h"

void change_env(node_t *node, char *value)
{
    int length = 0;

    if (value)
        length = my_strlen(value);
    free(node->var[1]);
    if (value)
        node->var[1] = my_strdup(value);
    free(node->env);
    node->env = my_malloc_ini(my_strlen(node->var[0]) + length + 1);
    node->env = my_strcat(node->env, node->var[0]);
    node->env = my_strcat(node->env, "=");
    if (value)
        node->env = my_strcat(node->env, value);
}

void new_env(node_t *node, char *name, char *value)
{
    int length = 0;
    char *data = NULL;

    if (value)
        length = my_strlen(value);
    data = my_malloc_ini(my_strlen(name) + length + 1);
    data = my_strcat(data, name);
    data = my_strcat(data, "=");
    if (value)
        data = my_strcat(data, value);
    new_node(node, data);
}

void find_env(node_t *node, char **arg)
{
    bool found = false;
    node_t *prev = NULL;


    while (node) {
        if (my_strcmp(node->var[0], arg[1]) == 0) {
            found = true;
            change_env(node, arg[2]);
        }
        prev = node;
        node = node->next;
    }
    if (!found)
        new_env(prev, arg[1], arg[2]);
}

int my_setenv(char **arg, node_t *node, history *history, int *fd)
{
    int length = my_arrlen(arg);

    if (length > 3) {
        my_puterror("setenv: Too many arguments.\n");
        return (84);
    } else if (length < 2)
        return (env(arg, node, history, fd));
    if (!(arg[1][0] >= 'A' && arg[1][0] <= 'z')) {
        my_puterror("setenv: Variable name must begin with a letter.\n");
        return (84);
    } else if (!my_stralphanum(arg[1])) {
        my_puterror("setenv: Variable name must contain"
        " alphanumeric characters.\n");
        return (84);
    }
    find_env(node, arg);
    return (0);
}
