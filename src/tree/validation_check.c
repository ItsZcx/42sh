/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** validation_check
*/

#include "shell.h"

bool valid_run(tree_t *leaf, int status)
{
    if (!leaf)
        return (true);
    if (leaf->opt == AND) {
        if (status == 0 || status == -69)
            return (true);
        return (false);
    }
    if (leaf->opt == OR) {
        if (status == 0)
            return (false);
        return (true);
    }
    return (true);
}
