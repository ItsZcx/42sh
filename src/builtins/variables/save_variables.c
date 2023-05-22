/*
** EPITECH PROJECT, 2023
** save_variables
** File description:
** function utils to manage local variables
*/

#include "shell.h"

char *get_var_file(node_t *node)
{
    char *home = find(node, "HOME");
    char *path = NULL;

    if (home)
        path = my_strcat2(find(node, "HOME"), "/.42variables");
    else
        path = ".42variables";
    return (path);
}

void init_variables_file(node_t *node)
{
    char *path = NULL;

    path = get_var_file(node);
    if (path)
        fclose(fopen(path, "w"));
}

void condition_set(char **arg, int i, int fd)
{
    for (int j = 0; arg[i - 1] && arg[i - 1][j]; j++) {
        if (arg[i - 1][j] == '=' && my_strcmp(arg[i - 1], "=") != 0) {
            write(fd, "\n", 1);
            break;
        }
    }
    if (i > 2 && arg[i - 2]) {
        if (my_strcmp(arg[i - 2], "=") == 0) {
            write(fd, "\n", 1);
        }
    }
}

void condition_set_n(char **arg, int my_fd)
{
    if (my_strcmp(arg[my_arrlen(arg) - 2], "=") != 0)
        write(my_fd, "\n", 1);
    for (int i = 0; arg[my_arrlen(arg) - 1] &&
    arg[my_arrlen(arg) - 1][i]; i++) {
        if (arg[my_arrlen(arg) - 1][i] = '=') {
            write(my_fd, "\n", 1);
            break;
        }
    }
}

int set(char **arg, node_t *node, history *history, int *fd)
{
    char *home = find(node, "HOME");
    char *path = NULL;
    int my_fd = 0;
    bool is_value = false;

    path = get_var_file(node);
    if (my_arrlen(arg) > 1) {
        my_fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);
        for (int i = 1; arg[i]; i++) {
            clean_char(arg[i], 34);
            clean_char(arg[i], 39);
            condition_set(arg, i, my_fd);
            write(my_fd, arg[i], my_strlen(arg[i]));
        }
        condition_set_n(arg, my_fd);
        close(my_fd);
    }
    return (0);
}
