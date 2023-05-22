/*
** EPITECH PROJECT, 2023
** B-PSU-200-BAR-2-1-42sh-alba.candelario-matas [WSL: Ubuntu]
** File description:
** history_switch
*/

#include "shell.h"

void print_cmd(char **new_arr, bool incorrect_long_event, history_ints *ints)
{
    bool valid = false;

    if (!new_arr || !new_arr[0])
        return;
    if (ints->exclamation_cmd == true && incorrect_long_event == false) {
        my_putstr(my_arr_to_str(new_arr));
        my_putstr("\n");
    }
}

bool fill_exclamation_cmd(char **arr, char **new_arr,
    history_ints *ints, history *history)
{
    char **temp = NULL;

    ints->exclamation_cmd = true;
    while (history->next != NULL)
        history = history->next;
    temp = cmd_finder(history, ints, new_arr, arr);
    if (temp == NULL) {
        free_arr(temp);
        return (false);
    }
    for (int i = 0; temp[i]; i++, ints->h_index++)
        new_arr[ints->h_index] = my_strdup(temp[i]);
    free_arr(temp);
    ints->a_index++;
    return (true);
}

void fill_normal_cmd(char **arr, char **new_arr, history_ints *ints)
{
    new_arr[ints->h_index] = my_strdup(arr[ints->a_index]);
    ints->h_index++;
    ints->a_index++;
}

void history_switch_logic(history_ints *ints, char **arr,
    char **new_arr, history **list)
{
    bool ret = false;

    for (ints->a_index = 0, ints->h_index = 0; arr && arr[ints->a_index];) {
        if (arr[ints->a_index][0] == '!')
            ret = fill_exclamation_cmd(arr, new_arr, ints, (*list));
        if (ret == false)
            fill_normal_cmd(arr, new_arr, ints);
        ret = false;
    }
    new_arr[ints->length] = NULL;
}

char **history_switch_cmd(char **arr, history **list)
{
    bool incorrect_long_event = false;
    history *end = (*list)->prev;
    history_ints *ints = init_ints();
    ints->length = new_arr_len(arr, end);
    char **new_arr = init_new_arr(ints);

    if (!new_arr || !ints)
        return (arr);
    history_switch_logic(ints, arr, new_arr, list);
    new_arr = envent_not_found(arr, new_arr, ints->length,
        &incorrect_long_event);
    if (new_arr[0] && new_arr[0][0] != '!')
        (*list) = create_history_node(list, my_arr_to_str(new_arr));
    if (incorrect_long_event == true)
        new_arr[0] = NULL;
    print_cmd(new_arr, incorrect_long_event, ints);
    return (new_arr);
}
