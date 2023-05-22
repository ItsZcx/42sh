/*
** EPITECH PROJECT, 2023
** tree
** File description:
** c file for tree
*/

#include "shell.h"

tree_t *new_leaf(tree_t *leaf, char **cmd, int opt)
{
    tree_t *new = malloc(sizeof(tree_t));

    if (!new)
        return (NULL);
    new->left = NULL;
    new->right = NULL;
    if (!cmd)
        new->status = SUCCESS;
    else
        new->status = QUEUE;
    new->opt = opt;
    new->cmd = cmd;
    new->pos = 0;
    if (leaf && !leaf->left)
        leaf->left = new;
    else if (leaf)
        leaf->right = new;
    return (new);
}

void free_tree(tree_t *leaf)
{
    if (leaf->left || leaf->right) {
        if (leaf->left)
            free_tree(leaf->left);
        if (leaf->right)
            free_tree(leaf->right);
    }
    free_arr(leaf->cmd);
    free(leaf);
}

bool was_successful(tree_t *head, tree_t *leaf)
{
    if (leaf && leaf->status == FAILURE)
        return (false);
    if (leaf)
        return (was_successful(head, find_node(head, leaf->pos - 1)));
    return (true);
}

tree_t *find_last(tree_t *head)
{
    while (head->right)
        head = head->right;
    return (head);
}
