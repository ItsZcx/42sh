/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** where.c
*/

#include "shell.h"

char *check_path_mod(char *path, char *cmd)
{
    if (is_xok(path) && access(path, X_OK) == 0)
        return (path);
    else
        return (NULL);
}

int find_path_mod(char **arr, char *cmd, int *fd)
{
    char *path = my_malloc_ini(large_path(arr) + my_strlen(cmd) + 1);
    int ret = 1;
    if (!path)
        return (1);
    if (access(cmd, X_OK) == 0 && is_xok(cmd))
        return (0);
    for (int x = 0; arr[x]; x++) {
        for (int i = 0; path[i]; i++)
            path[i] = '\0';
        if (!arr || !arr[x])
            break;
        path = my_strcat(path, arr[x]);
        path = my_strcat(path, "/");
        path = my_strcat(path, cmd);
        if (access(path, X_OK) == 0) {
            dprintf(fd[2], "%s\n",check_path_mod(path, cmd));
            ret = 0;
        }
    }
    return (ret);
}

bool check_builtin_where(char *arg, int *fd)
{
    char *builtins[FUNCT_NUM] = {"cd", "exit", "env", "setenv", "unsetenv",
    "echo", "history", "alias", "set", "which", "where"};
    for (int i = 0; i < FUNCT_NUM; i++) {
        if (my_strcmp(builtins[i], arg) == 0) {
            dprintf(fd[2], "%s is a shell built-in\n", arg);
            return (true);
        }
    }
    return (false);
}

int if_exists_where(char *arg, node_t *node, int *fd)
{
    char *path = find(node, "PATH");
    char **arr = NULL;
    char *cmd = NULL;
    int ret = 0;

    if (check_builtin_where(arg, fd))
        return (0);
    if (!path)
        arr = my_new_split(my_strdup("/bin\n"), "\n");
    else if (path == NULL_2)
        arr = NULL;
    else
        arr = my_new_split(path, ":");
    ret = find_path_mod(arr, arg, fd);
    return (ret);
}

int where(char **arg, node_t *node, history *history, int *fd)
{
    int ret = 0;
    int tmp = 0;
    if (array_length(arg) < 2) {
        dprintf(fd[2], "which: Too few arguments.\n");
        return (1);
    }
    for (int j = 1; arg[j]; j++) {
        if (tmp = if_exists_where(arg[j], node, fd) > ret)
            ret = tmp;
    }
    errno = 0;
    return (ret);
}
