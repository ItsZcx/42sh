/*
** EPITECH PROJECT, 2023
** parse
** File description:
** c file for parse
*/

#include "shell.h"

bool error_parse(ssize_t nread)
{
    if (nread == -1) {
        if (errno == 25)
            return (true);
        if (errno != 0)
            perror(NULL);
        else
            write(1, "exit\n", 5);
        return (true);
    }
    return (false);
}

void clean_string(char *str)
{
    for (int i = 0; str[i]; i++) {
        while (str[i] && str[i] == ';') {
            str[i] = (str[i + 1] == ';') ? ' ' : ';';
            i++;
        }
    }
}

tree_t *parse(history **list)
{
    size_t n = 0;
    tree_t *tree = NULL;
    char *lineptr = NULL;
    ssize_t nread = getline(&lineptr, &n, stdin);

    if (error_parse(nread))
        return (NULL);
    lineptr[my_strlen(lineptr) - 1] = '\0';
    clean_string(lineptr);
    char **arr = history_switch_cmd(my_split_operators
    (my_new_split(lineptr, " \t")), list);
    tree = create_tree(arr);
    free(lineptr);
    return (tree);
}
