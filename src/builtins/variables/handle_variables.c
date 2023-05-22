/*
** EPITECH PROJECT, 2023
** echo_variables
** File description:
** function utils for using display variables
*/

#include "shell.h"

void modify_var_value(char *var_value, char **arg, int i)
{
    if (var_value) {
        arg[i] = my_reallococo(arg[i], my_strlen(var_value));
        arg[i] = my_strcpy(arg[i], var_value);
    } else {
        arg[i] = my_reallococo(arg[i], 1);
        arg[i][0] = '\0';
    }
}

char **is_dollar(char **arg, int i, int *j, node_t *node)
{
    char *var = get_var(arg, i, j);
    char **var_arr = NULL;
    bool exists = (my_strlen(var) == 0) ? true : false;
    char *var_value = NULL;
    char *path = get_var_file(node);
    char **str_path = NULL;
    str_path = my_new_split(read_file(path, file_size(path)), "\n");
    if (var && my_strlen(var) != 0) {
        var_value = search_local_var(str_path, var_arr, var, &exists);
        if (!exists)
            var_value = search_env_var(node, var, &exists);
        if (!exists) {
            write(2, var, my_strlen(var));
            write(2, ": undefined variable.\n", 22);
            return (NULL);
        }
        modify_var_value(var_value, arg, i);
    }
    return (arg);
}

char **get_tmp_arg(char **arg)
{
    char **tmp_arg = malloc(sizeof(char *) * my_arrlen(arg));
    for (int i = 0; arg[i]; i++) {
        tmp_arg[i] = my_malloc_ini(my_strlen(arg[i]));
        my_strcpy(tmp_arg[i], arg[i]);
    }
    tmp_arg[my_arrlen(arg)] = NULL;
    return (tmp_arg);
}

char **check_var_return(char **tmp_arg, char **arg, bool *var_ok)
{
    if (!tmp_arg) {
        (*var_ok) = false;
        return (arg);
    } else {
        (*var_ok) = true;
        return (tmp_arg);
    }
}

char **check_variables(char **arg, node_t *node, bool *var_ok)
{
    char *ret = NULL;
    char *path = get_var_file(node);
    char **tmp_arg = NULL;

    if (!is_directory(path))
        return (arg);
    tmp_arg = get_tmp_arg(arg);
    for (int i = 0; tmp_arg && tmp_arg[i]; i++) {
        for (int j = 0; tmp_arg && tmp_arg[i][j]; j++) {
            tmp_arg = is_dollar(tmp_arg, i, &j, node);
        }
    }
    return (check_var_return(tmp_arg, arg, var_ok));
}
