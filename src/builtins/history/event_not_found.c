/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** event_not_found
*/

#include "shell.h"

char **fill_minus_first_cmd(char **temp2, char **arr)
{
    int pos = 0;

    for (int index = 1; arr[index]; index++, pos++)
        temp2[pos] = my_strdup(arr[index]);
    temp2[pos] = NULL;
    return (temp2);
}

char **init_temp(void)
{
    char **temp = malloc(sizeof(char *) * 2);

    temp[0] = NULL;
    temp[1] = NULL;
    return (temp);
}

char **exclamation_hastag(char **arr, char **temp)
{
    if (arr[0][0] == '!' && arr[0][1] == '#') {
        my_putstr("\n");
        return (temp);
    }
    return (NULL);
}

char **envent_not_found(char **arr, char **new_arr,
    int length, bool *incorrect_long_event)
{
    char **temp = init_temp();
    if (arr == NULL || exclamation_hastag(arr, temp) != NULL)
        return (temp);
    char **temp2 = malloc(sizeof(char *) * my_arrlen(arr));
    if (length == 0 && arr[0] && arr[0][0] == '!') {
        if (arr[0][0] == '!' && arr[0][1] == '!')
            my_puterror("0");
        if (arr[0][0] == '!' && arr[0][1] != '!' && arr[0][1] != '#')
            my_puterror(cut_str_start(arr[0], 1));
        my_puterror(": Event not found.\n");
        return (temp);
    }
    if (length > 0 && new_arr[0] && new_arr[0][0] == '!') {
        (*incorrect_long_event) = true;
        my_puterror(cut_str_start(arr[0], 1));
        my_puterror(": Event not found.\n");
        temp2 = fill_minus_first_cmd(temp2, arr);
        return (temp2);
    }
    return (new_arr);
}
