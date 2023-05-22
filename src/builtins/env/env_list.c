/*
** EPITECH PROJECT, 2023
** linked_list
** File description:
** c file for linked list
*/

#include "shell.h"

node_t *new_node(node_t *node, char *data)
{
    node_t *new = malloc(sizeof(node_t));

    if (!new)
        return (NULL);
    if (node)
        node->next = new;
    new->env = my_strdup(data);
    new->var = my_new_split(data, "=");
    new->next = NULL;
    return (new);
}

node_t *env_to_node(char **env)
{
    node_t *head = NULL;
    node_t *next = NULL;

    if (!env || !env[0])
        return (NULL);
    head = new_node(NULL, env[0]);
    next = head;
    for (int i = 1; env[i]; i++) {
        next = new_node(next, env[i]);
        if (!next)
            return (NULL);
    }
    return (head);
}

char *find(node_t *node, char *name)
{
    while (node) {
        if (my_strcmp(node->var[0], name) == 0)
            break;
        node = node->next;
    }
    if (node && node->var[1])
        return (my_strdup(node->var[1]));
    else if (node)
        return (NULL_2);
    else
        return (NULL);
}

int list_size(node_t *node, int *x)
{
    int size = 0;
    int length = 0;

    while (node) {
        size++;
        length = my_strlen(node->env);
        if (length > *x)
            *x = length;
        node = node->next;
    }
    return (size);
}

char **list_to_arr(node_t *node)
{
    int x = 0;
    int y = list_size(node, &x);
    char **arr = NULL;

    if (y <= 0)
        return (NULL);
    arr = my_arr_ini(x, y);
    if (!arr)
        return (NULL);
    for (int j = 0; j < y; j++) {
        arr[j] = my_strcpy(arr[j], node->env);
        node = node->next;
    }
    return (arr);
}
