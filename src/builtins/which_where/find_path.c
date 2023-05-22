/*
** EPITECH PROJECT, 2023
** find_path
** File description:
** c file for find path
*/

#include "shell.h"

bool is_xok(char *path)
{
    DIR *dir = opendir(path);

    if (dir) {
        closedir(dir);
        return (false);
    }
    return (true);
}

int large_path(char **arr)
{
    int big = 0;
    int length = 0;

    if (!arr)
        return (0);
    for (int j = 0; arr[j]; j++) {
        length = my_strlen(arr[j]);
        if (length > big)
            big = length;
    }
    return (big);
}

char *check_path(char *path, char *cmd)
{
    if (is_xok(path) && access(path, X_OK) == 0)
        return (path);
    else {
        my_puterror(cmd);
        if (!is_xok(cmd) || access(cmd, F_OK) == 0)
            write(2, ": Permission denied.\n", 21);
        else
            write(2, ": Command not found.\n", 21);
    }
    return (NULL);
}

char *find_path(char **arr, char *cmd)
{
    char *path = my_malloc_ini(large_path(arr) + my_strlen(cmd) + 1);

    if (!path)
        return (NULL);
    if (access(cmd, X_OK) == 0 && is_xok(cmd))
        return (cmd);
    for (int x = 0; access(path, X_OK) != 0; x++) {
        for (int i = 0; path[i]; i++)
            path[i] = '\0';
        if (!arr || !arr[x])
            break;
        path = my_strcat(path, arr[x]);
        path = my_strcat(path, "/");
        path = my_strcat(path, cmd);
    }
    return (check_path(path, cmd));
}
