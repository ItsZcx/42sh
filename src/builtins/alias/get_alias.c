/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** get_alias.c
*/

#include "shell.h"


bool is_directory(char* path)
{
    struct stat path_stat;
    if (stat(path, &path_stat) != 0)
        return (false);
    return (true);
}

char *get_alias_file(node_t *node)
{
    char *path = find(node, "HOME");
    if (path && is_directory(path))
        path = my_strcat2(find(node, "HOME"), "/.42shrc");
    else
        path = ".42shrc";
    return (path);
}

int array_length(char **arr)
{
    int length = 0;
    while (arr[length]) {
        length++;
    }
    return (length);
}

char **get_alias(char **arg, char **alias)
{
    int alias_len = array_length(alias) - 1;
    int arg_len = array_length(arg);
    int pos = 0;
    char **new_arg = malloc((alias_len + arg_len + 1) * sizeof(char*));

    for (int i = 1; alias[i]; i++) {
        new_arg[pos] = alias[i];
        pos++;
    }
    for (int i = 1; arg[i]; i++) {
        new_arg[pos] = arg[i];
        pos++;
    }
    new_arg[pos] = NULL;
    return (new_arg);
}

char **check_alias(char **arg, node_t *node)
{
    char **str = NULL;
    char *path = NULL;
    char **alias = NULL;
    char *input = arg[0];
    path = get_alias_file(node);
    if (is_directory(path))
        str = my_new_split(read_file(path, file_size(path)), "\n");
    else
        return (arg);
    for (int y = 0; str[y]; y++) {
        alias = my_new_split(str[y], " ");
        if (input && alias && strcmp(input, alias[0]) == 0) {
            arg = get_alias(arg, alias);
        }
    }
    return (arg);
}
