/*
** EPITECH PROJECT, 2023
** echo_backlash
** File description:
** function utils to manage backlash escapes for echo
*/

#include "shell.h"

bool is_backlash(char letter)
{
    char list[9] = "abefnrtv";

    for (int i = 0; list[i]; i++) {
        if (list[i] == letter)
            return (true);
    }
    if (letter == 92)
        return (true);
    return (false);
}

void display_backlash(char letter, int *fd)
{
    if (letter == '\\')
        write(fd[2], "\\", 1);
    if (letter == 'a')
        write(fd[2], "\a", 1);
    if (letter == 'b')
        write(fd[2], "\b", 1);
    if (letter == 'e')
        write(fd[2], "\e", 1);
    if (letter == 'f')
        write(fd[2], "\f", 1);
    if (letter == 'n')
        write(fd[2], "\n", 1);
    if (letter == 'r')
        write(fd[2], "\r", 1);
    if (letter == 't')
        write(fd[2], "\t", 1);
    if (letter == 'v')
        write(fd[2], "\v", 1);
}
