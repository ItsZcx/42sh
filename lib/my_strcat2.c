/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** my_strcat2
*/

#include "my_string.h"

char *my_strcat2(char *dest, char *concatenate)
{
    int index = 0;
    int final_index = 0;
    char *final = malloc(sizeof(char) *
        (my_strlen(dest) + my_strlen(concatenate) + 1));

    while (dest[index] != '\0') {
        final[final_index] = dest[index];
        final_index++;
        index++;
    }
    index = 0;
    while (concatenate[index] != '\0') {
        final[final_index] = concatenate[index];
        final_index++;
        index++;
    }
    final[final_index] = '\0';
    return (final);
}
