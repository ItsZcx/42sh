/*
** EPITECH PROJECT, 2023
** loop
** File description:
** c file for loop
*/

#include "shell.h"

void close_fd(int *fd)
{
    if (fd && fd[0] != 0 && fd[0] != 1 && fd[0] != 2)
        close(fd[0]);
    if (fd && fd[2] != 0 && fd[2] != 1 && fd[2] != 2)
        close(fd[2]);
}

void update(tree_t *head, tree_t *cmd, tree_t *opt, int status)
{
    tree_t *next_opt = find_node(head, cmd->pos + 1);
    tree_t *next_cmd = find_node(head, cmd->pos + 2);

    if (status == 0) {
        cmd->status = SUCCESS;
        if (opt)
            opt->status = SUCCESS;
        if (next_opt && (next_opt->opt == MORE || next_opt->opt == LESS
        || next_opt->opt == INSERT || next_opt->opt == EXTRACT))
            next_cmd->status = SUCCESS;
    } else {
        cmd->status = FAILURE;
        if (opt)
            opt->status = FAILURE;
        if (next_opt && (next_opt->opt == MORE || next_opt->opt == LESS
        || next_opt->opt == INSERT || next_opt->opt == EXTRACT))
            next_cmd->status = FAILURE;
    }
}

int loop_cmd(node_t *node, tree_t *head, history *h)
{
    int *fd = new_fd();
    int status = -69;
    list_t *fd_list = NULL;
    tree_t *cmd = next_cmd(head, 0);
    tree_t *opt = NULL;

    while (cmd) {
        opt = find_node(head, cmd->pos - 1);
        fd_list = new_fdlist(fd_list, new_pipe());
        if (fd = setfd(fd, head, cmd, fd_list), fd[1] == 1)
            status = 1;
        if (fd[1] != 1 && valid_run(opt, status))
            status = run_cmd(node, cmd->cmd, fd, h);
        close_fd(fd);
        update(head, cmd, opt, status);
        cmd = next_cmd(head, 0);
    }
    free_fdlist(fd_list, fd);
    return ((was_successful(head, find_last(head))) ? 0 : status);
}

int loop(char **env)
{
    int ret = 0;
    tree_t *tree = NULL;
    node_t *head = env_to_node(env);
    history *list = init_history_alias(head);
    if (!head)
        return ((env && env[0]) ? 84 : 0);
    while (1) {
        if (isatty(0) == 1)
            prompt();
        tree = parse(&list);
        if (!tree)
            return ((errno == 25) ? ret : 84);
        if (ret == 0)
            ret = loop_cmd(head, tree, list);
        else
            loop_cmd(head, tree, list);
        free_tree(tree);
    }
    free_list(head);
    return (ret);
}
