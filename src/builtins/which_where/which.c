/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** which.c
*/

#include "shell.h"

bool check_builtin(char *arg, int *fd)
{
    char *builtins[FUNCT_NUM] = {"cd", "exit", "env", "setenv", "unsetenv",
    "echo", "history", "alias", "set", "which", "where"};
    for (int i = 0; i < FUNCT_NUM; i++) {
        if (my_strcmp(builtins[i], arg) == 0) {
            dprintf(fd[2], "%s: shell built-in command.\n", arg);
            return (true);
        }
    }
    return (false);
}

int if_exists(char *arg, node_t *node, int *fd)
{
    char *path = find(node, "PATH");
    char **arr = NULL;
    char *cmd = NULL;

    if (check_builtin(arg, fd))
        return (0);
    if (!path)
        arr = my_new_split(my_strdup("/bin\n"), "\n");
    else if (path == NULL_2)
        arr = NULL;
    else
        arr = my_new_split(path, ":");
    cmd = find_path(arr, arg);
    if (cmd) {
        dprintf(fd[2], "%s\n", cmd);
        return (0);
    } else
        return (1);
}

int which(char **arg, node_t *node, history *history, int *fd)
{
    int ret = 0;
    int tmp = 0;
    if (array_length(arg) < 2) {
        dprintf(fd[2], "which: Too few arguments.\n");
        return (1);
    }
    for (int j = 1; arg[j]; j++) {
        if (tmp = if_exists(arg[j], node, fd) > ret)
            ret = tmp;
    }
    errno = 0;
    return (ret);
}
