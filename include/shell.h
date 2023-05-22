/*
** EPITECH PROJECT, 2023
** shell
** File description:
** h file for shell
*/

#ifndef SHELL_H_
    #define SHELL_H_

    #define _GNU_SOURCE

    #include <stdlib.h>
    #include <stdio.h>
    #include <unistd.h>
    #include <dirent.h>
    #include <signal.h>
    #include <string.h>
    #include <errno.h>
    #include <stdbool.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <sys/wait.h>
    #include <time.h>

    #include "my_string.h"
    #include "my_num.h"
    #include "my_arr.h"

    #define FUNCT_NUM 11
    #define NULL_2 ((void *)1)
    #define OPT_NUM 8

    enum operators{
        SEMI,
        PIPE,
        MORE,
        LESS,
        INSERT,
        EXTRACT,
        AND,
        OR,
        NONE
    };

    enum status{
        SUCCESS,
        FAILURE,
        QUEUE
    };

    typedef struct l_history {
        int pos;
        char *cmd;
        char *time;
        struct l_history *next;
        struct l_history *prev;
    } history;

    typedef struct l_history_ints {
        int a_index;
        int h_index;
        int length;
        bool exclamation_cmd;
    } history_ints;

    typedef struct node_s {
        char *env;
        char **var;
        struct node_s *next;
    } node_t;

    typedef struct fptr_s {
        char *name;
        int (*function)(char **, node_t *, history *, int *);
    } fptr_t;

    typedef struct tree_s {
        int opt;
        int status;
        int pos;
        char **cmd;
        struct tree_s *left;
        struct tree_s *right;
    } tree_t;

    typedef struct list_s {
        bool redirected;
        int *fd;
        struct list_s *next;
        struct list_s *prev;
    } list_t;

    int my_cd(char **arg, node_t *node, history *history, int *fd);
    int my_exit(char **arg, node_t *node, history *history, int *fd);
    int env(char **arg, node_t *node, history *history, int *fd);
    int my_setenv(char **arg, node_t *node, history *history, int *fd);
    int my_unsetenv(char **arg, node_t *node, history *history, int *fd);
    int my_echo(char **arg, node_t *node, history *history, int *fd);
    int run_cmd(node_t *node, char **cmd, int *fd, history *history);
    int list_size(node_t *node, int *x);
    int update_env(char *var, char *value, node_t *node);
    int loop(char **env);
    int find_and_or(char **arr);
    int find_redirection(char **arr);
    int find_semi(char **arr);
    int which_operator(char *str);
    int new_fd_out(char *path, int fd);
    int open_fd_out(char *path, int fd);
    int *new_pipe(void);
    int execute(char **arg, node_t *node, int *fd);
    int *new_fd(void);
    int open_fd_in(char *path, int fd);
    int *setfd(int *fd, tree_t *head, tree_t *cmd, list_t *list);
    bool are_operators(char **arr);
    bool was_successful(tree_t *head, tree_t *leaf);
    bool check_echo_flag(char **arg);
    bool check_colons(char **arg, bool flag_n);
    bool is_backlash(char letter);
    char *find(node_t *node, char *name);
    char *find_path(char **arr, char *cmd);
    char **my_split_operators(char **arr);
    char **list_to_arr(node_t *node);
    tree_t *parse(history **list);
    tree_t *new_leaf(tree_t *leaf, char **cmd, int opt);
    tree_t *create_tree(char **cmd);
    tree_t *next_cmd(tree_t *head, int i);
    tree_t *find_node(tree_t *head, int pos);
    tree_t *find_last(tree_t *head);
    node_t *env_to_node(char **env);
    node_t *new_node(node_t *node, char *data);
    list_t *new_fdlist(list_t *node, int *fd);
    list_t *list_first(list_t *node);
    list_t *list_last(list_t *node);
    void change_env(node_t *node, char *value);
    void signal_handler(int signal);
    void free_list(node_t *node);
    void prompt(void);
    void free_tree(tree_t *leaf);
    void display_tree(tree_t *leaf);
    void create_leafs(tree_t *leaf);
    void show_leaf(tree_t *leaf);
    void display_backlash(char letter, int *fd);
    void close_pipe(int fd1, int fd2);
    void free_fdlist(list_t *list, int *fd);
    void redirect(int fd1, int fd2, int fd3, int fd4);
    int which(char **arg, node_t *node, history *history, int *fd);
    bool check_builtin(char *arg, int *fd);
    int where(char **arg, node_t *node, history *history, int *fd);
    int large_path(char **arr);
    bool is_xok(char *path);

    // Alias
    int alias(char **arg, node_t *node, history *history, int *fd);
    void init_alias_file(node_t *node);
    int clean_char(char *string, char c);
    char *read_file(char *path, int size);
    long int file_size(char *file);
    char **check_alias(char **arg, node_t *node);
    char *get_alias_file(node_t *node);
    void display_alias(node_t *node, int *fd);
    bool is_directory(char* path);
    int array_length(char **arr);

    // History
    int new_arr_len(char **arr, history *end);
    int my_history(char **arg, node_t *node, history *history, int *fd);
    char *my_strcat2(char *dest, char *concatenate);
    char **history_switch_cmd(char **arr, history **history);
    char **envent_not_found(char **arr, char **new_arr,
    int length, bool *non_long_event);
    history *init_history_node(void);
    history *init_history_alias(node_t *node);
    history *to_last_hist_node(history *history);
    history *create_history_node(history **curr, char *cmd);
    history_ints *init_ints(void);
    char **hist_substitution(char *cmd, history *end);
    char **last_hist_substitution(char *cmd, history *end);
    char **hist_num_substitution(char *cmd, history *end);
    char **dup_substitution(history_ints *ints, char **new_arr, char **arr);
    char **num_substitution(char *cmd, history *end, int num);
    char **cmd_finder(history *end, history_ints *ints,
        char **new_arr, char **arr);
    char **dup_array(char **arr, int size);
    char **init_new_arr(history_ints *ints);
    int hist_substitution_length(char *cmd, history *end);
    int last_hist_substitution_length(char *cmd, history *end);
    int hist_num_substitution_length(char *cmd, history *end);
    int num_length(char *cmd, history *end, int num);
    history *init_history(void);

    // Variables
    void init_variables_file(node_t *node);
    int set(char **arg, node_t *node, history *history, int *fd);
    char **check_variables(char **arg, node_t *node, bool *var_ok);
    char *get_var_file(node_t *node);
    bool is_directory(char* path);
    char *my_reallococo(char *str, size_t new_size);
    char *search_local_var(char **str_path, char **var_arr,
        char *var, bool *exists);
    char *get_var(char **arg, int i, int *j);
    char *search_env_var(node_t *node, char *var, bool *exists);

    bool valid_run(tree_t *leaf, int status);
    int new_fd_in(char *path, int fd);
    char **add_colour(char **arr);

#endif
