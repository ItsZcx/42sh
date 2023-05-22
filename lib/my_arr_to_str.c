/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** my_arr_to_str
*/

#include "my_string.h"

int find_lenght(char **arr)
{
    int index = 0;
    int count = 0;

    while (arr[index]) {
        count += my_strlen(arr[index]) + 1;
        index++;
    }
    return (count);
}

char *my_arr_to_str(char **arr)
{
    int pos = 0;
    int length = 0;
    char *str = NULL;

    if (!arr)
        return (NULL);
    length = find_lenght(arr);
    str = malloc(sizeof(char) * (length + 1));
    for (int index = 0; arr[index]; index++) {
        for (int j = 0; arr[index][j]; j++) {
            str[pos] = arr[index][j];
            pos++;
        }
        str[pos] = ' ';
        pos++;
    }
    str[pos] = '\0';
    return (str);
}
