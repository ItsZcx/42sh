/*
** EPITECH PROJECT, 2023
** cd
** File description:
** file for cd
*/

#include "shell.h"

int change_dir(char *dir)
{
    if (!dir || chdir(dir) == -1 || (errno != 0 && errno != 25)) {
        if (dir)
            my_puterror(dir);
        write(2, ": ", 2);
        if (!dir)
            write(2, "No such file or directory", 25);
        else
            my_puterror(strerror(errno));
        write(2, ".\n", 2);
        return (84);
    }
    return (0);
}

int home(char *path, node_t *node)
{
    char *home_path = find(node, "HOME");
    char *dir = NULL;
    int length = 0;

    if (!home_path || home_path == NULL_2) {
        my_puterror(strerror(ENOENT));
        write(2, "\n", 1);
        return (84);
    }
    if (path)
        length = my_strlen(path);
    dir = my_malloc_ini(my_strlen(home_path) + length);
    dir = my_strcat(dir, home_path);
    for (int i = 1; path && path[i]; i++)
        dir[my_strlen(dir)] = path[i];
    return (change_dir(dir));
}

int previous(char *path, node_t *node)
{
    int ret = 0;
    char *pwd = find(node, "PWD");
    char *oldpwd = find(node, "OLDPWD");

    if (pwd == NULL_2)
        pwd = NULL;
    if (oldpwd == NULL_2)
        oldpwd = NULL;
    if (my_strcmp(pwd, oldpwd) != 0)
        ret = change_dir(path);
    else
        ret = change_dir(NULL);
    if (!path)
        return (84);
    return (ret);
}

int my_cd(char **arg, node_t *node, history *history, int *fd)
{
    char *path = getcwd(NULL, 0);
    int ret = 0;

    if (my_arrlen(arg) == 1 || !arg[1][0] || my_strcmp(arg[1], "~") == 0)
        ret = home(arg[1], node);
    else if (my_strcmp(arg[1], "-") == 0)
        ret = previous(find(node, "OLDPWD"), node);
    else
        ret = change_dir(arg[1]);
    if (ret == 0 && my_strcmp(path, find(node, "OLDPWD")) != 0)
        update_env("OLDPWD", path, node);
    if (ret == 0)
        update_env("PWD", getcwd(NULL, 0), node);
    if (!path)
        perror(NULL);
    errno = 0;
    return (ret);
}
