/*
** EPITECH PROJECT, 2023
** run_cmd
** File description:
** c file for run cmd
*/

#include "shell.h"

fptr_t fptr[FUNCT_NUM] = {
    {"cd", &my_cd},
    {"exit", &my_exit},
    {"env", &env},
    {"setenv", &my_setenv},
    {"unsetenv", &my_unsetenv},
    {"echo", &my_echo},
    {"history", &my_history},
    {"alias", &alias},
    {"set", &set},
    {"which", &which},
    {"where", &where}

};

int run_cmd(node_t *node, char **cmd, int *fd, history *history)
{
    int ret = 0;
    bool known = false;
    bool var_ok = true;

    cmd = check_alias(cmd, node);
    cmd = check_variables(cmd, node, &var_ok);
    if (!var_ok)
        return (84);
    for (int i = 0; i < FUNCT_NUM; i++) {
        if (my_strcmp(cmd[0], fptr[i].name) == 0) {
            known = true;
            ret = fptr[i].function(cmd, node, history, fd);
        }
    }
    if (!known && cmd[0] && cmd[0][0]) {
        cmd = add_colour(cmd);
        ret = execute(cmd, node, fd);
    }
    return (ret);
}
