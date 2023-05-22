/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** file.c
*/

#include "shell.h"

long int file_size(char *file)
{
    struct stat fi;

    if (stat(file, &fi) != -1) {
        if (fi.st_mode & S_IFMT == S_IFDIR)
            return (-2);
        return (fi.st_size);
    } else
        return (-1);
}

char *read_file(char *path, int size)
{
    char *buf = NULL;
    int fd = 0;

    if (size < 0)
        return (NULL);
    if ((fd = open(path, O_RDONLY)) == -1)
        return (NULL);
    buf = my_malloc_ini(size + 1);
    if (!buf)
        return (NULL);
    if (read(fd, buf, size) == -1) {
        free(buf);
        return (NULL);
    }
    if (close(fd) == -1) {
        free(buf);
        return (NULL);
    }
    return (buf);
}
