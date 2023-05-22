/*
** EPITECH PROJECT, 2023
** free_list
** File description:
** c file for free list
*/

#include "shell.h"

void free_list(node_t *node)
{
    node_t *next = NULL;

    while (node) {
        next = node->next;
        free(node);
        node = next;
    }
}
