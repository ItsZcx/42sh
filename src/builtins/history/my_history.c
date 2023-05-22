/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** my_history
*/

#include "shell.h"

int my_history(char **arg, node_t *node, history *history, int *fd)
{
    while (history->prev)
        history = history->prev;
    while (history->next != NULL) {
        dprintf(fd[2], "     %d\t%s\t%s\n",
        history->pos, history->time, history->cmd);
        history = history->next;
    }
    return (0);
}
