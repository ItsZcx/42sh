/*
** EPITECH PROJECT, 2023
** display_tree
** File description:
** c file for display tree
*/

#include "shell.h"

void show_leaf2(tree_t *leaf)
{
    if (!leaf)
        write(1, "NULL\n", 5);
    if (leaf && !leaf->cmd)
        write(1, "cmd: NONE\n", 10);
    for (int j = 0; leaf && leaf->cmd && leaf->cmd[j]; j++) {
        write(1, "cmd: ", 5);
        my_putstr(leaf->cmd[j]);
        write(1, "\n", 1);
    }
    if (leaf) {
        write(1, "pos: ", 5);
        my_put_nbr(leaf->pos);
        write(1, "\n", 1);
    }
}

void show_leaf(tree_t *leaf)
{
    show_leaf2(leaf);
    if (!leaf)
        return;
    switch (leaf->opt) {
    case (SEMI): write(1, "opt: ;\n", 7); break;
    case (PIPE): write(1, "opt: |\n", 7); break;
    case (MORE): write(1, "opt: >\n", 7); break;
    case (LESS): write(1, "opt: <\n", 7); break;
    case (INSERT): write(1, "opt: >>\n", 8); break;
    case (EXTRACT): write(1, "opt: <<\n", 8); break;
    case (AND): write(1, "opt: &&\n", 8); break;
    case (OR): write(1, "opt: ||\n", 8); break;
    default: write(1, "opt: NONE\n", 10); break;
    }
    switch (leaf->status) {
    case (SUCCESS): write(1, "status: SUCCESS\n", 16); break;
    case (FAILURE): write(1, "status: FAILURE\n", 16); break;
    case (QUEUE): write(1, "status: QUEUE\n", 14); break;
    }
    write(1, "\n", 1);
}

void display_tree(tree_t *leaf)
{
    if (leaf->left)
        display_tree(leaf->left);
    show_leaf(leaf);
    if (leaf->right)
        display_tree(leaf->right);
}
