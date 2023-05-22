/*
** EPITECH PROJECT, 2023
** search_variables
** File description:
** function util to search variables
*/

#include "shell.h"

char *set_var_value(char **var_arr)
{
    char *var_value = NULL;

    if (var_arr[1]) {
        var_value = my_malloc_ini(my_strlen(var_arr[1]));
        var_value = my_strcpy(var_value, var_arr[1]);
    }
    return (var_value);
}

char *search_local_var(char **str_path, char **var_arr,
char *var, bool *exists)
{
    char *var_value = NULL;

    for (int a = 0; str_path[a]; a++) {
        var_arr = my_new_split(str_path[a], "=");
        if (var_arr && my_strcmp(var, var_arr[0]) == 0) {
            var_value = set_var_value(var_arr);
            (*exists) = true;
        }
    }
    return (var_value);
}

int count_var_len(char **arg, int i, int *j)
{
    int var_len = 0;

    for (int count = (*j); arg[i][count]; count++) {
        if (arg[i][count] == ' ' || arg[i][count] == 92 || arg[i][count] == '$')
            break;
        var_len++;
    }
    return (var_len);
}

char *get_var(char **arg, int i, int *j)
{
    int var_len = 0;
    char *var = NULL;

    if (arg[i][(*j)] == '$') {
        (*j)++;
        var_len = count_var_len(arg, i, j);
        var = my_malloc_ini(var_len);
        for (int count = 0; count < var_len; count++, (*j)++)
            var[count] = arg[i][(*j)];
        if (var != NULL)
            (*j)--;
    }
    return (var);
}
