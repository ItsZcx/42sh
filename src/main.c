/*
** EPITECH PROJECT, 2023
** main
** File description:
** main file for shell
*/

#include "shell.h"

int main(int ac, char **av, char **env)
{
    if (ac != 1)
        return (84);
    return (loop(env));
}
