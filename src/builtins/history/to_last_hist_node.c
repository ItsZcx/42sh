/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** to_last_hist_node
*/

#include "shell.h"

history *to_last_hist_node(history *history)
{
    if (history == NULL)
        return (NULL);
    while (history->next != NULL)
        history = history->next;
    return (history);
}
