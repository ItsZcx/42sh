/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** history
*/

#include "shell.h"

history_ints *init_ints(void)
{
    history_ints *ints = malloc(sizeof(history_ints));

    if (!ints)
        return (NULL);
    ints->a_index = 0;
    ints->h_index = 0;
    ints->length = 0;
    ints->exclamation_cmd = false;
    return (ints);
}

history *init_history(void)
{
    history *list = malloc(sizeof(history));

    if (!list)
        return (NULL);
    list->time = NULL;
    list->cmd = NULL;
    list->next = NULL;
    list->prev = NULL;
    return (list);
}

history *init_history_node(void)
{
    history *x_node = malloc(sizeof(history));

    if (!x_node)
        return (NULL);
    x_node->pos = 0;
    x_node->cmd = NULL;
    x_node->time = NULL;
    x_node->next = NULL;
    x_node->prev = NULL;
    return (x_node);
}

history *create_history_node(history **curr, char *cmd)
{
    (*curr)->next = init_history_node();
    time_t now = time(NULL);
    struct tm *tm_now = localtime(&now);

    if (!cmd)
        return (NULL);
    (*curr)->cmd = my_strdup(cmd);
    if ((*curr)->prev)
        (*curr)->pos = (*curr)->prev->pos + 1;
    else
        (*curr)->pos = 1;
    (*curr)->time = my_malloc_ini(6);
    strftime((*curr)->time, sizeof((*curr)->time), "%H:%M", tm_now);
    (*curr)->next->next = NULL;
    (*curr)->next->prev = (*curr);
    return ((*curr)->next);
}

history *init_history_alias(node_t *node)
{
    init_alias_file(node);
    init_variables_file(node);
    return (init_history());
}
