/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** display.c
*/

#include "shell.h"

bool last_alias(char **file, char *string, int pos)
{
    char **alias = NULL;
    bool status = true;

    for (int y = 0; file[y]; y++) {
        alias = my_new_split(file[y], " ");
            if (my_strcmp(alias[0], string) == 0 && pos < y) {
                status = false;
            }
    }
    return (status);
}

void display_values(char **alias, int i, int *fd)
{
    if (alias[i]) {
        if (array_length(alias) > 2 && i == 1)
            dprintf(fd[2],"(");
        dprintf(fd[2], "%s", alias[i]);
        if (array_length(alias) > 2 && !alias[i + 1])
            dprintf(fd[2],")");
        if (!alias[i + 1])
            dprintf(fd[2],"\n");
        if (alias[i + 1] && i > 0)
            dprintf(fd[2]," ");
        if (i == 0)
            dprintf(fd[2],"\t");
    }
}

void display_alias(node_t *node, int *fd)
{

    char **str = NULL;
    char *path = NULL;
    char **alias = NULL;
    path = get_alias_file(node);
    if (is_directory(path))
        str = my_new_split(read_file(path, file_size(path)), "\n");
    else
        return;
    for (int y = 0; str[y]; y++) {
        alias = my_new_split(str[y], " ");
        for (int i = 0; alias[i] && last_alias(str, alias[i], y); i++) {
            display_values(alias, i, fd);
        }
    }
}
