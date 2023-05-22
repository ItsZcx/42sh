/*
** EPITECH PROJECT, 2023
** find_tree
** File description:
** c file for find tree
*/

#include "shell.h"

tree_t *next_cmd(tree_t *head, int i)
{
    tree_t *leaf = NULL;

    while ((leaf = find_node(head, i))) {
        if (leaf->status == QUEUE && leaf->opt == NONE)
            return (leaf);
        i++;
    }
    return (NULL);
}

tree_t *find_node(tree_t *head, int pos)
{
    tree_t *tmp = NULL;

    if (head->pos == pos)
        return (head);
    if (head->left)
        tmp = find_node(head->left, pos);
    if (tmp)
        return (tmp);
    if (head->right)
        tmp = find_node(head->right, pos);
    if (tmp)
        return (tmp);
    return (NULL);
}
