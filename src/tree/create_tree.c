/*
** EPITECH PROJECT, 2023
** create_tree
** File description:
** c file for create tree
*/

#include "shell.h"

void create_branch(tree_t *leaf, int pos)
{
    char **arr = my_split_arr(leaf->cmd, pos + 1);
    int last = my_arrlen(leaf->cmd) - 1;

    if (!arr)
        return;
    leaf->opt = which_operator(leaf->cmd[last]);
    leaf->cmd[last] = NULL;
    if (leaf->cmd && leaf->cmd[0])
        create_leafs(new_leaf(leaf, leaf->cmd, NONE));
    if (arr && arr[0])
        create_leafs(new_leaf(leaf, arr, NONE));
    leaf->cmd = NULL;
}

void create_leafs(tree_t *leaf)
{
    int and_or = 0;
    int redir = 0;
    int semi = 0;

    if (leaf && are_operators(leaf->cmd)) {
        semi = find_semi(leaf->cmd);
        and_or = find_and_or(leaf->cmd);
        redir = find_redirection(leaf->cmd);
        if (semi != -1)
            create_branch(leaf, semi);
        if (semi == -1 && and_or != -1)
            create_branch(leaf, and_or);
        if (and_or == -1 && semi == -1 && redir != -1)
            create_branch(leaf, redir);
    }
}

tree_t *assign_pos(tree_t *node, int *pos)
{
    tree_t *tmp = NULL;

    if (node->left)
        tmp = assign_pos(node->left, pos);
    node->pos = (*pos)++;
    if (tmp)
        return (tmp);
    if (node->right)
        tmp = assign_pos(node->right, pos);
    if (tmp)
        return (tmp);
    return (NULL);
}

tree_t *create_tree(char **cmd)
{
    tree_t *head = new_leaf(NULL, cmd, NONE);
    int pos = 0;

    if (!head)
        return (NULL);
    create_leafs(head);
    assign_pos(head, &pos);
    return (head);
}
