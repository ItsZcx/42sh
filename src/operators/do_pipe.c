/*
** EPITECH PROJECT, 2023
** do_pipe
** File description:
** c file for do pipe
*/

#include "shell.h"

int *new_fd(void)
{
    int *fd = malloc(sizeof(int) * 4);

    if (!fd)
        return (NULL);
    fd[0] = 0;
    fd[1] = STDIN_FILENO;
    fd[2] = 0;
    fd[3] = STDOUT_FILENO;
    return (fd);
}

int *new_pipe(void)
{
    int *fd = malloc(sizeof(int) * 2);

    if (!fd)
        return (NULL);
    if (pipe2(fd, O_NONBLOCK) != 0) {
        perror(NULL);
        return (NULL);
    }
    return (fd);
}

void close_pipe(int fd1, int fd2)
{
    close(fd1);
    close(fd2);
}

bool open_fd(tree_t *head, tree_t *cmd, tree_t *opt, list_t *list)
{
    tree_t *next = find_node(head, cmd->pos + 2);

    if (opt && opt->opt == MORE && next)
        list->fd[1] = new_fd_out(next->cmd[0], list->fd[1]);
    if (opt && opt->opt == LESS && next)
        list->fd[0] = open_fd_in(next->cmd[0], list->fd[0]);
    if (opt && opt->opt == INSERT && next)
        list->fd[1] = open_fd_out(next->cmd[0], list->fd[1]);
    if (opt && opt->opt == EXTRACT && next)
        list->fd[0] = new_fd_in(next->cmd[0], list->fd[0]);
    if ((opt && opt->opt != MORE && opt->opt != LESS && opt->opt != INSERT
    && opt->opt != EXTRACT) || next || !opt)
        return (true);
    else
        write(2, "Missing name for redirect.\n", 27);
    return (false);
}

int *setfd(int *fd, tree_t *head, tree_t *cmd, list_t *list)
{
    tree_t *opt = find_node(head, cmd->pos + 1);
    for (int i = 0; i < 2; i++)
        fd[i] = STDIN_FILENO;
    for (int i = 2; i < 4; i++)
        fd[i] = STDOUT_FILENO;
    if (!open_fd(head, cmd, opt, list))
        return (fd[1] = 1, fd);
    if (list->prev && list->prev->redirected)
        fd[0] = list->prev->fd[0];
    if (opt && (opt->opt == LESS || opt->opt == EXTRACT))
        fd[0] = list->fd[0];
    if (opt && (opt->opt == MORE || opt->opt == INSERT || opt->opt == PIPE)) {
        if (opt->opt == PIPE && !next_cmd(head, opt->pos + 1)) {
            write(2, "Invalid null command.\n", 22);
            return (fd[1] = 1, fd);
        }
        fd[2] = list->fd[1];
        list->redirected = true;
    }
    return (fd);
}
