/*
** EPITECH PROJECT, 2023
** fd_list
** File description:
** c file fd list
*/

#include "shell.h"

list_t *new_fdlist(list_t *node, int *fd)
{
    list_t *list = malloc(sizeof(list_t));

    if (!list)
        return (NULL);
    list->next = malloc(sizeof(list_t));
    if (!list->next)
        return (NULL);
    list->next = NULL;
    list->prev = node;
    list->fd = fd;
    list->redirected = false;
    return (list);
}

list_t *list_first(list_t *node)
{
    while (node->prev)
        node = node->prev;
    return (node);
}

list_t *list_last(list_t *node)
{
    while (node->next)
        node = node->next;
    return (node);
}

void free_fdlist(list_t *list, int *fd)
{
    list_t *next = list;

    free(fd);
    while (next) {
        next = list->next;
        free(list->fd);
        free(list);
        list = next;
    }
}
