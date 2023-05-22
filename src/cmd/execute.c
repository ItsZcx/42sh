/*
** EPITECH PROJECT, 2023
** execute
** File description:
** c file for execute
*/

#include "shell.h"

char *get_cmd(char **arg, node_t *node)
{
    char *path = find(node, "PATH");
    char **arr = NULL;
    char *cmd = NULL;

    if (!path)
        arr = my_new_split(my_strdup("/bin\n"), "\n");
    else if (path == NULL_2)
        arr = NULL;
    else
        arr = my_new_split(path, ":");
    cmd = find_path(arr, arg[0]);
    if (path && path != NULL_2)
        free(path);
    if (arr)
        free_arr(arr);
    return (cmd);
}

void child(char **arg, node_t *node, int *fd)
{
    char *cmd = get_cmd(arg, node);
    char **env = list_to_arr(node);

    if (fd)
        redirect(fd[0], fd[1], fd[2],fd[3]);
    if (execve(cmd, arg, env) == -1) {
        if (errno == 8) {
            my_puterror(cmd);
            write(2, ": Exec format error. " \
            "Binary file not executable.\n", 49);
        }
        exit(1);
    }
}

int execute(char **arg, node_t *node, int *fd)
{
    pid_t pid = fork();
    int wstatus;

    if (pid == -1)
        perror(NULL);
    else if (pid == 0)
        child(arg, node, fd);
    else
        waitpid(-1, &wstatus, 0);
    if (WIFEXITED(wstatus) && isatty(0) == 0)
        return (WEXITSTATUS(wstatus));
    if (WIFSIGNALED(wstatus)) {
        signal_handler(WTERMSIG(wstatus));
        if (WCOREDUMP(wstatus))
            write(2, " (core dumped)", 14);
        write(2, "\n", 1);
        exit(WEXITSTATUS(wstatus));
    }
    return (WEXITSTATUS(wstatus));
}
