/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** alias.c
*/

#include "shell.h"


void init_alias_file(node_t *node)
{
    char *path = NULL;

    path = get_alias_file(node);
    if (path)
        fclose(fopen(path, "w"));
    if (access(".42shrc", F_OK) == 0)
        fclose(fopen(".42shrc", "w"));
    errno = 0;
}

int alias(char **arg, node_t *node, history *history, int *fd)
{
    char *home = find(node, "HOME");
    char *path = NULL;
    int new_fd;

    path = get_alias_file(node);
    if (arg[0] && !arg[1]) {
        display_alias(node, fd);
        return (0);
    }
    if (arg[1] && arg[2]) {
        new_fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);
        for (int i = 1; arg[i]; i++) {
            clean_char(arg[i], 34);
            write(new_fd, arg[i], my_strlen(arg[i]));
            write(new_fd, " ", 1);
        }
        write(new_fd, "\n", 1);
        close(new_fd);
    }
}
