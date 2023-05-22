/*
** EPITECH PROJECT, 2023
** redirect
** File description:
** c file for redirect
*/

#include "shell.h"

void redirect(int fd1, int fd2, int fd3, int fd4)
{
    if (fd1 != 0 && fd1 != 1 && fd1 != 2) {
        dup2(fd1, fd2);
        close(fd1);
    }
    if (fd3 != 0 && fd3 != 1 && fd3 != 2) {
        dup2(fd3, fd4);
        close(fd3);
    }
}

int new_fd_out(char *path, int fd)
{
    int new_fd = open(path, O_RDWR | O_CREAT | O_TRUNC, 0644);

    if (new_fd < 0) {
        perror(NULL);
        return (-1);
    }
    close(fd);
    return (new_fd);
}

int open_fd_out(char *path, int fd)
{
    int new_fd = open(path, O_RDWR | O_CREAT | O_APPEND, 0644);

    if (new_fd < 0) {
        perror(NULL);
        return (-1);
    }
    close(fd);
    return (new_fd);
}

int open_fd_in(char *path, int fd)
{
    int new_fd = open(path, O_RDWR, 0644);

    if (new_fd < 0) {
        perror(NULL);
        return (-1);
    }
    close(fd);
    return (new_fd);
}

int new_fd_in(char *path, int fd)
{
    FILE *file = tmpfile();
    char *lineptr = NULL;
    size_t n = 0;
    ssize_t size = 0;
    char *delim = my_malloc_ini(strlen(path + 1));

    delim = strcat(delim, path);
    delim = strcat(delim, "\n");
    while (1) {
        write(1, "? ", 2);
        size += getline(&lineptr, &n, stdin);
        if (lineptr && strcmp(lineptr, delim) == 0)
            break;
        if (size == -1 && errno != 0)
            return (-1);
        fwrite(lineptr, sizeof(char), strlen(lineptr), file);
    }
    rewind(file);
    close(fd);
    return (file->_fileno);
}
