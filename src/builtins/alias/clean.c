/*
** EPITECH PROJECT, 2022
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas
** File description:
** clean.c
*/

#include "shell.h"

int clean_char(char *string, char c)
{
    int i, j, k;
    int count = 0;
    for (j = 0, k = 0; j < strlen(string); j++) {
        if (string[j] != c) {
            string[k] = string[j];
            k++;
        } else
            count ++;
    }
    string[k] = '\0';
    return (count);
}
