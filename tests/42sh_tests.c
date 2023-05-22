/*
** EPITECH PROJECT, 2022
** unit_tests
** File description:
** Unit tests for 42sh Epitech project
**
** ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ WARING ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓
** →→→    Take into cosideration that the result of some test can vary depending     ←←←
** →→→  on the files present at the repository. To minimize the possible problems,   ←←←
** →→→  check that the output of "ls -a" is the same as this one before doing make:  ←←←
** →→→             ".  ..  .git  Makefile  include  lib  src  tests"                 ←←←
** ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ WARING ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑
*/

#include "shell.h"
#include <criterion/criterion.h>
#include <criterion/types.h>
#include <criterion/redirect.h>
#include <sys/wait.h>

//////////////////////////////////////////////////////////////
///////////////             ls_suit            ///////////////
//////////////////////////////////////////////////////////////

Test(ls_suit, ls_0)
{
    int diff_return = 0;

    system("echo -n \"ls\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(ls_suit, ls_1)
{
    int diff_return = 0;

    system("echo -n \"ls -l\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(ls_suit, ls_2)
{
    int diff_return = 0;

    system("echo -n \"ls -la\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -la\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -la\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(ls_suit, ls_3)
{
    int diff_return = 0;

    system("echo -n \"ls -lah\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lah\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lah\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(ls_suit, ls_4)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a -h\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(ls_suit, ls_5)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h --author -c\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a -h --author -c\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h --author -c\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////            touch_suit          ///////////////
//////////////////////////////////////////////////////////////

Test(touch_suit, touch_0)
{
    int diff_return = 0;

    system("echo -n \"ls\n touch a\n ls\n\" | tcsh > /tmp/tcsh_output.txt");
    system("rm a");
    system("echo -n \"ls\n touch a\n ls\n\" | ./42sh > /tmp/42sh_output.txt");
    system("rm a");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls\\n touch a\\n ls\\n\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(touch_suit, touch_1)
{
    int diff_return = 0;

    system("echo -n \"ls\n touch a b c\n ls\n\" | tcsh > /tmp/tcsh_output.txt");
    system("rm a b c");
    system("echo -n \"ls\n touch a b c\n ls\n\" | ./42sh > /tmp/42sh_output.txt");
    system("rm a b c");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls\\n touch a b c\\n ls\\n\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////             rm_suit            ///////////////
//////////////////////////////////////////////////////////////

Test(rm_suit, rm_0)
{
    int diff_return = 0;

    system("echo -n \"rm a\n\" | tcsh 2> /tmp/tcsh_output.txt");
    system("echo -n \"rm a\n\" | ./42sh 2> /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"rm a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(rm_suit, rm_1)
{
    int diff_return = 0;

    system("echo -n \"rm a b c\n\" | tcsh 2> /tmp/tcsh_output.txt");
    system("echo -n \"rm a b c\n\" | ./42sh 2> /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"rm a b c\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////      line_formatting_suit      ///////////////
//////////////////////////////////////////////////////////////

Test(line_formatting_suit, line_formatting_0)
{
    int diff_return = 0;

    system("echo -n \" ls -a\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \" ls -a\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \" ls -a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_1)
{
    int diff_return = 0;

    system("echo -n \"     ls\t\t -a\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"     ls\t\t -a\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"     ls\t\t -a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_2)
{
    int diff_return = 0;

    system("echo -n \"     ls\t\t -a\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"     ls\t\t -a\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"     ls\t\t -a\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_3)
{
    int diff_return = 0;

    system("echo -n \"ls -a\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -a\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -a\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_4)
{
    int diff_return = 0;

    system("echo -n \"ls \t-a\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls \t-a\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls \t-a\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_5)
{
    int diff_return = 0;

    system("echo -n \"ls\t-a\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls\t-a\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls\t-a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(line_formatting_suit, line_formatting_6)
{
    int diff_return = 0;

    system("echo -n \"\tls -a\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"\tls -a\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\tls -a\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////            env_suite           ///////////////
//////////////////////////////////////////////////////////////

Test(env_suit, env0)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[6] = {"x_var", "x_var", "x_var", "x_var", "x_var", NULL};
    char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\n");

    head = env_to_node(arr);
    cr_redirect_stdout();
    env(NULL, head, NULL, fd);

    cr_assert_stdout_eq_str(expected_output, "Command \"env\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    cr_free(expected_output);
}

//////////////////////////////////////////////////////////////
///////////////          setenv_suite          ///////////////
//////////////////////////////////////////////////////////////

Test(setenv_suit, setenv0)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[7] = {"x_var", "x_var", "x_var", "x_var", "x_var", "a=a", NULL};
    char *cmd[4] = {"setenv", "a", "a", NULL};
    char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\na=a\n");

    head = env_to_node(arr);
    my_setenv(cmd, head, NULL, fd);
    cr_redirect_stdout();
    env(NULL, head, NULL, fd);

    cr_assert_stdout_eq_str(expected_output, "Command \"setenv a a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(arr);
    cr_free(expected_output);
}

Test(setenv_suit, setenv_length6)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[6] = {"x_var", "x_var", "x_var", "x_var", "x_var", NULL};
    char *cmd[7] = {"setenv", "a", "a", "a", "a", "a", NULL};
    char *expected_output = my_strdup("setenv: Too many arguments.\n");

    head = env_to_node(arr);
    cr_redirect_stderr();
    my_setenv(cmd, head, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"setenv a a a a a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(arr);
    cr_free(expected_output);
}

Test(setenv_suit, setenv_length1)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[6] = {"x_var", "x_var", "x_var", "x_var", "x_var", NULL};
    char *cmd[2] = {"a", NULL};
    char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\n");

    head = env_to_node(arr);
    cr_redirect_stdout();
    my_setenv(cmd, head, NULL, fd);

    cr_assert_stdout_eq_str(expected_output, "Command \"setenv a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(arr);
    cr_free(expected_output);
}

Test(setenv_suit, setenv_begining)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[6] = {"x_var", "x_var", "x_var", "x_var", "x_var", NULL};
    char *cmd[4] = {"setenv", "?", "a", NULL};
    char *expected_output = my_strdup("setenv: Variable name must begin with a letter.\n");

    head = env_to_node(arr);
    cr_redirect_stderr();
    my_setenv(cmd, head, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"setenv ? a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(arr);
    cr_free(expected_output);
}

Test(setenv_suit, setenv_alphanum)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[6] = {"x_var", "x_var", "x_var", "x_var", "x_var", NULL};
    char *cmd[4] = {"setenv", "P=-.,,.+`", "a", NULL};
    char *expected_output = my_strdup("setenv: Variable name must contain alphanumeric characters.\n");

    head = env_to_node(arr);
    cr_redirect_stderr();
    my_setenv(cmd, head, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"setenv P=-.,,.+` a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(arr);
    cr_free(expected_output);
}

//////////////////////////////////////////////////////////////
///////////////         unsetenv_suite         ///////////////
//////////////////////////////////////////////////////////////

Test(unsetenv_suit, length1)
{
    int ret = 0;
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arg[2] = {"unsetenv", NULL};

    cr_redirect_stdout();
    ret = my_unsetenv(arg, NULL, NULL, fd);

    cr_assert(ret == 84, "Command \"unsetenv\" is not working correctly");

    // Free memory
    for (int i = 0; arg[i]; i++)
        cr_free(arg[i]);
    cr_free(arg);
}

Test(unsetenv_suit, unset_variable)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[7] = {"x_var", "x_var", "x_var", "x_var", "x_var", "a=a", NULL};
    char *arg[3] = {"unsetenv", "a", NULL};
    char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\n");

    head = env_to_node(arr);
    my_unsetenv(arg, head, NULL, fd);
    cr_redirect_stdout();
    env(NULL, head, NULL, fd);

    cr_assert_stdout_eq_str(expected_output, "Command \"unsetenv a\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; arg[i]; i++)
        cr_free(arg[i]);
    cr_free(arg);
    cr_free(arr);
    cr_free(expected_output);
}

Test(unsetenv_suit, unset_inexisting_variable)
{
    node_t *head = NULL;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arr[7] = {"x_var", "x_var", "x_var", "x_var", "x_var", "a=a", NULL};
    char *arg[3] = {"unsetenv", "z", NULL};
    char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\na=a\n");

    head = env_to_node(arr);
    my_unsetenv(arg, head, NULL, fd);
    cr_redirect_stdout();
    env(NULL, head, NULL, fd);

    cr_assert_stdout_eq_str(expected_output, "Command \"unsetenv z\" is not working correctly");

    // Free memory
    for (int i = 0; arr[i]; i++)
        cr_free(arr[i]);
    for (int i = 0; arg[i]; i++)
        cr_free(arg[i]);
    cr_free(arg);
    cr_free(arr);
    cr_free(expected_output);
}

// Test(unsetenv_suit, unset_multiple_variables)
// {
//     node_t *head = NULL;
//     int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
//     char *arr[9] = {"x_var", "x_var", "x_var", "x_var", "x_var", "a=a", "b=b", "c=c", NULL};
//     char *arg[5] = {"unsetenv", "a", "b", "c", NULL};
//     char *expected_output = my_strdup("x_var\nx_var\nx_var\nx_var\nx_var\n");

//     head = env_to_node(arr);
//     my_unsetenv(arg, head, NULL, fd);
//     cr_redirect_stdout();
//     env(NULL, head, NULL, fd);

//     cr_expect_stdout_eq_str(expected_output, "Command \"unsetenv a b c\" is not working correctly");

//     // Free memory
//     for (int i = 0; arr[i]; i++)
//         cr_free(arr[i]);
//     for (int i = 0; arg[i]; i++)
//         cr_free(arg[i]);
//     cr_free(arg);
//     cr_free(arr);
//     cr_free(expected_output);
// }

//////////////////////////////////////////////////////////////
///////////////           exit_suite           ///////////////
//////////////////////////////////////////////////////////////

Test(exit_suit, exit_a)
{
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *cmd[3] = {"exit", "a", NULL};
    char *expected_output = my_strdup("exit: Expression Syntax.\n");

    cr_redirect_stderr();
    my_exit(cmd, NULL, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"exit a\" is not working correctly");

    // Free memory
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(expected_output);
}

Test(exit_suit, exit_0a)
{
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *cmd[3] = {"exit", "0a", NULL};
    char *expected_output = my_strdup("exit: Badly formed number.\n");

    cr_redirect_stderr();
    my_exit(cmd, NULL, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"exit 0a\" is not working correctly");

    // Free memory
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(expected_output);
}

Test(exit_suit, exit_length3)
{
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *cmd[4] = {"exit", "0", "0", NULL};
    char *expected_output = my_strdup("exit: Expression Syntax.\n");

    cr_redirect_stderr();
    my_exit(cmd, NULL, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"exit 0 0\" is not working correctly");

    // Free memory
    for (int i = 0; cmd[i]; i++)
        cr_free(cmd[i]);
    cr_free(cmd);
    cr_free(expected_output);
}

Test(exit_suit, just_exit)
{
    int ret = -1;

    ret = system("echo -n \"exit\n\" | ./42sh");

    cr_assert(WEXITSTATUS(ret) == 0, "Command \"exit\" is not working correctly");
}

Test(exit_suit, exit_10)
{
    int ret = -1;

    ret = system("echo -n \"exit 10\n\" | ./42sh");

    cr_assert(WEXITSTATUS(ret) == 10, "Command \"exit 10\" is not working correctly");
}

Test(exit_suit, exit_18)
{
    int ret = -1;

    ret = system("echo -n \"exit 18\n\" | ./42sh");

    cr_assert(WEXITSTATUS(ret) == 18, "Command \"exit 18\" is not working correctly");
}

//////////////////////////////////////////////////////////////
///////////////            cd_suite            ///////////////
//////////////////////////////////////////////////////////////

Test(cd_suit, cd)
{
    int diff_return = 0;

    system("echo -n \"cd\n pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cd\n pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd\\n pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(cd_suit, cd_one_dot)
{
    int diff_return = 0;

    system("echo -n \"cd .\n pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cd .\n pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd .\\n pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(cd_suit, cd_two_dot)
{
    int diff_return = 0;

    system("echo -n \"cd ..\n pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cd ..\n pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd ..\\n pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(cd_suit, cd_four_dot)
{
    int diff_return = 0;

    system("echo -n \"cd ../../\n pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cd ../../\n pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd ../../\\n pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(cd_suit, cd_tilde)
{
    int diff_return = 0;

    system("echo -n \"cd ~\n pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cd ~\n pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd ~\\n pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(cd_suit, cd_non_home_path)
{
    char *expected_output = my_strdup("No such file or directory\n");

    cr_redirect_stderr();
    cr_redirect_stdout();
    system("echo -n \"unsetenv HOME\n cd ~\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"unsetenv HOME\\n cd\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

// Test(cd_suit, first_cmd_cd_dash)
// {
//     int diff_return = 0;

//     system("echo -n \"cd -\n\" | tcsh 2> /tmp/tcsh_output.txt");
//     system("echo -n \"cd -\n\" | ./42sh 2> /tmp/42sh_output.txt");
//     diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

//     cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd -\" is different from TCSH");

//     system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
// }

Test(cd_suit, cd_non_OLDPWD_path)
{
    char *expected_output = my_strdup(": No such file or directory.\n");

    cr_redirect_stderr();
    system("echo -n \"unsetenv OLDPWD\n cd -\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"unsetenv OLDPWD\\n cd -\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(cd_suit, cd_non_existant)
{
    int diff_return = 0;

    system("echo -n \"cd nig\n\" | tcsh 2> /tmp/tcsh_output.txt");
    system("echo -n \"cd nig\n\" | ./42sh 2> /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cd nig\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////           echo_suite           ///////////////
//////////////////////////////////////////////////////////////

Test(echo_suite, echo_hello_0)
{
    int diff_return = 0;

    system("echo -n \"echo \"hello\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo \"hello\"\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo \"hello\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_hello_1)
{
    int diff_return = 0;

    system("echo -n \"echo hello\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo hello\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo hello\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_bsn)
{
    int diff_return = 0;

    system("echo -n \"echo\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_space)
{
    int diff_return = 0;

    system("echo -n \"echo \n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo \n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo \" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_2backslash_prints_one_bs)
{
    int diff_return = 0;

    system("echo -n \"echo hel\\\\\\\\\\\\\\\\lo\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo hel\\\\\\\\\\\\\\\\lo\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo hel\\\\\\\\\\\\\\\\lo\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_1backslash_prints_zero_bs)
{
    int diff_return = 0;

    system("echo -n \"echo hel\\\\\\\\lo\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo hel\\\\\\\\lo\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo hel\\\\\\\\lo\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_backslash_tab_prints_tab)
{
    int diff_return = 0;

    system("echo -n \"echo \"hel\\\\\\\\\\tlo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo \"hel\\\\\\\\\\tlo\"\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"hel\\\\\\\\\\tlo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_1backslash_plus_prints_bsplus)
{
    int diff_return = 0;

    system("echo -n \"echo \"hel\\+lo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo \"hel\\+lo\"\n\" | ./42sh > /tmp/42sh_output.txt");

    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo \"hel\\+lo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, check_double_collons)
{
    int ret = -1;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arg[3] = {"echo", "\"double_collons", NULL};
    char *expected_output = my_strdup("Unmatched '\"'.\n");

    cr_redirect_stderr();
    ret = my_echo(arg, NULL, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"echo \"double_collons\" is not working correctly");

    // Free memory
    for (int i = 0; arg[i]; i++)
        cr_free(arg[i]);
    cr_free(arg);
    cr_free(expected_output);
}

Test(echo_suite, check_single_collons)
{
    int ret = -1;
    int fd[4] = {STDIN_FILENO, STDIN_FILENO, STDOUT_FILENO, STDOUT_FILENO};
    char *arg[3] = {"echo", "\'single_collons", NULL};
    char *expected_output = my_strdup("Unmatched '\''.\n");

    cr_redirect_stderr();
    ret = my_echo(arg, NULL, NULL, fd);

    cr_assert_stderr_eq_str(expected_output, "Command \"echo \'single_collons\" is not working correctly");

    // Free memory
    for (int i = 0; arg[i]; i++)
        cr_free(arg[i]);
    cr_free(arg);
    cr_free(expected_output);
}

Test(echo_suite, echo_flag_e)
{
    int diff_return = 0;

    system("echo -n \"echo -e \"hel\\\\\\\\\\tlo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo -e \"hel\\\\\\\\\\tlo\"\n\" | ./42sh > /tmp/42sh_output.txt");

    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo -e \"hel\\\\\\\\\\tlo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_flag_cappital_e)
{
    int diff_return = 0;

    system("echo -n \"echo -E \"hel\\\\\\\\\\tlo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo -E \"hel\\\\\\\\\\tlo\"\n\" | ./42sh > /tmp/42sh_output.txt");

    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo -e \"hel\\\\\\\\\\tlo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_flag_n_e)
{
    int diff_return = 0;

    system("echo -n \"echo -ne \"hel\\\\\\\\\\tlo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo -ne \"hel\\\\\\\\\\tlo\"\n\" | ./42sh > /tmp/42sh_output.txt");

    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo -e \"hel\\\\\\\\\\tlo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(echo_suite, echo_flag_n_cappital_e)
{
    int diff_return = 0;

    system("echo -n \"echo -nE \"hel\\\\\\\\\\tlo\"\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"echo -nE \"hel\\\\\\\\\\tlo\"\n\" | ./42sh > /tmp/42sh_output.txt");

    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"echo -e \"hel\\\\\\\\\\tlo\"\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

////////////////////////////////////////////////////////
///////////         history_suite          ///////////////
//////////////////////////////////////////////////////////

// Test(history_suite, history)
// {
//     time_t now = time(NULL);
//     struct tm *tm_now = localtime(&now);
//     char *time_str = malloc(sizeof(char) * (6 + 1));
//     strftime(time_str, sizeof(time_str), "%H:%M", tm_now);
//     char *expected_output = my_strcat2(my_strcat2("     1  ", time_str), "   history \n");

//         // my_putstr("expected_output:\n"); my_putstr(expected_output); my_putstr(".sys:\n");
//         // system("echo -n \"history\n\" | ./42sh"); my_putstr(".\n");
//     cr_redirect_stdout();
//     system("echo -n \"history\n\" | ./42sh");
//     cr_assert_stdout_eq_str(expected_output, "Command \"history\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

// Test(history_suite, multiple_cmd)
// {
//     time_t now = time(NULL);
//     struct tm *tm_now = localtime(&now);
//     char *time_str = malloc(sizeof(char) * (6 + 1));
//     strftime(time_str, sizeof(time_str), "%H:%M", tm_now);
//     char *expected_output = NULL;
//     expected_output = my_strcat2(my_strcat2("     1  ", time_str), "   cd .. \n");
//     expected_output = my_strcat2(my_strcat2(expected_output, my_strcat2("     2  ", time_str)), "   cd .. \n");
//     expected_output = my_strcat2(my_strcat2(expected_output, my_strcat2("     3  ", time_str)), "   history \n");

//         // my_putstr("expected_output:\n"); my_putstr(expected_output); my_putstr(".sys:\n");
//         // system("echo -n \"cd ..\n cd ..\n history\n\" | ./42sh"); my_putstr(".\n");
//     cr_redirect_stdout();
//     system("echo -n \"cd ..\n cd ..\n history\n\" | ./42sh");

//     cr_assert_stdout_eq_str(expected_output, "Command \"cd ..\\n cd ..\\n history\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

Test(history_suite, start_one_exaclamation)
{
    char *expected_output = my_strdup(": Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_double_exaclamation)
{
    char *expected_output = my_strdup("0: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!!\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!!\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_minus_5)
{
    char *expected_output = my_strdup("-5: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!-5\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!-5\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_minus_0)
{
    char *expected_output = my_strdup("-0: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!-0\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!-0\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_5)
{
    char *expected_output = my_strdup("5: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!5\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!5\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_0)
{
    char *expected_output = my_strdup("0: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!0\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!0\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_hastag)
{
    char *expected_output = my_strdup("\n");

    cr_redirect_stdout();
    system("echo -n \"!#\n\" | ./42sh");

    cr_assert_stdout_eq_str(expected_output, "Command \"!#\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_ls)
{
    char *expected_output = my_strdup("ls: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!ls\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!ls\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

Test(history_suite, start_exclamation_ls_one_argument)
{
    char *expected_output = my_strdup("ls: Event not found.\n");

    cr_redirect_stderr();
    system("echo -n \"!ls -l\n\" | ./42sh");

    cr_assert_stderr_eq_str(expected_output, "Command \"!ls -l\" is different from TCSH");

    // Free memory
    cr_free(expected_output);
}

// Test(history_suite, ls_double_exclamation)
// {
//     char *expected_output = my_strdup("42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\nls \n42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\n");

//     cr_redirect_stdout();
//     system("echo -n \"ls\n !!\n\" | ./42sh");

//     cr_assert_stdout_eq_str(expected_output, "Command \"ls\\n !!\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

// Test(history_suite, ls_exclamation_0)
// {
//     char *expected_output = my_strdup("42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\nls \n42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\n");

//     cr_redirect_stderr();
//     cr_redirect_stdout();
//     system("echo -n \"ls\n !0\n\" | ./42sh");

//     cr_assert_stdout_eq_str(expected_output, "Command \"ls\\n !0\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

// Test(history_suite, ls_exclamation_minus_1)
// {
//     char *expected_output = my_strdup("42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\nls \n42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\n");

//     cr_redirect_stdout();
//     system("echo -n \"ls\n !-1\n\" | ./42sh");

//     cr_assert_stdout_eq_str(expected_output, "Command \"ls\\n !-1\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

// Test(history_suite, ls_exclamation_ls)
// {
//     char *expected_output = my_strdup("42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\nls \n42sh\nMakefile\ninclude\nlib\nsrc\ntests\nunit_test\nunit_test-42sh_tests.gcda\nunit_test-42sh_tests.gcno\n");

//     cr_redirect_stdout();
//     system("echo -n \"ls\n !ls\n\" | ./42sh");

//     cr_assert_stdout_eq_str(expected_output, "Command \"ls\\n !ls\" is different from TCSH");

//     // Free memory
//     cr_free(expected_output);
// }

Test(history_suite, ls_exclamation_hastag)
{
    char *expected_output1 = my_strdup("ls ls \n");
    char *expected_output2 = my_strdup("ls: cannot access 'ls': No such file or directory\n");

    cr_redirect_stdout();
    cr_redirect_stderr();
    system("echo -n \"ls !#\n\" | ./42sh");

    cr_assert_stdout_eq_str(expected_output1, "Command \"ls\\n !#\" is different from TCSH");
    cr_assert_stderr_eq_str(expected_output2, "Command \"ls\\n !#\" is different from TCSH");

    // Free memory
    cr_free(expected_output1);
    cr_free(expected_output2);
}

//////////////////////////////////////////////////////////////
///////////////        separators_suite        ///////////////
//////////////////////////////////////////////////////////////

Test(separators_suite, pwd_separator_pwd_no_spaces)
{
    int diff_return = 0;

    system("echo -n \"pwd;pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd;pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd;pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, pwd_separator_pwd_spaces)
{
    int diff_return = 0;

    system("echo -n \"pwd ; pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd ; pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd ; pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, pwd_separator_pwd_multiple_spaces)
{
    int diff_return = 0;

    system("echo -n \"pwd   ;   pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd   ;   pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd   ;   pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, pwd_separator_pwd_separator)
{
    int diff_return = 0;

    system("echo -n \"pwd ; pwd;\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd ; pwd;\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd ; pwd;\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, pwd_separator_pwd_multiple_separators)
{
    int diff_return = 0;

    system("echo -n \"pwd ; pwd;;;;;\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd ; pwd;;;;;\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd ; pwd;;;;;\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, separator_pwd_separator_pwd)
{
    int diff_return = 0;

    system("echo -n \"; pwd ; pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"; pwd ; pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"; pwd ; pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(separators_suite, multiple_pwd_with_multiple_separators)
{
    int diff_return = 0;

    system("echo -n \"pwd ; pwd ; pwd ; pwd ; pwd ; pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd ; pwd ; pwd ; pwd ; pwd ; pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd ; pwd ; pwd ; pwd ; pwd ; pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////           pipes_suite          ///////////////
//////////////////////////////////////////////////////////////

Test(pipes_suite, ls_pipe_grep_0)
{
    int diff_return = 0;

    system("echo -n \"ls | grep Makefile\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls | grep Makefile\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls | grep Makefile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_pipe_grep_1)
{
    int diff_return = 0;

    system("echo -n \"ls | grep unit_test\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls | grep unit_test\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls | grep unit_test\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_pipe_grep_2)
{
    int diff_return = 0;

    system("echo -n \"ls | grep asd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls | grep asd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls | grep asd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_pipe_grep_3)
{
    int diff_return = 0;

    system("echo -n \"ls -lha | grep Makefile\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lha | grep Makefile\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lha | grep Makefile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_pipe_grep_4)
{
    int diff_return = 0;

    system("echo -n \"ls -lha | grep unit_test\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lha | grep unit_test\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lha | grep unit_test\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_pipe_grep_5)
{
    int diff_return = 0;

    system("echo -n \"ls -lha | grep asd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lha | grep asd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lha | grep asd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, cat_pipe_grep_6)
{
    int diff_return = 0;

    system("echo -n \"cat Makefile | grep a\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cat Makefile | grep a\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat Makefile | grep a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, cat_pipe_grep_8)
{
    int diff_return = 0;

    system("echo -n \"cat Makefile | grep doesnt_exist\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cat Makefile | grep doesnt_exist\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat Makefile | grep doesnt_exist\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, ls_spaces_pipe_grep)
{
    int diff_return = 0;

    system("echo -n \"ls    |    grep Makefile\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls    |    grep Makefile\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls    |    grep Makefile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, spaces_ls_pipe_grep)
{
    int diff_return = 0;

    system("echo -n \"    ls | grep unit_test    \n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"    ls | grep unit_test    \n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"    ls | grep unit_test    \" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_ls_pipe_grep)
{
    int diff_return = 0;

    system("echo -n \"   ls   |   grep   asd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"   ls   |   grep   asd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"   ls   |   grep   asd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_ls_separated_pipe_grep)
{
    int diff_return = 0;

    system("echo -n \"  ls   -l   -h   -a |   grep   Makefile  \n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"  ls   -l   -h   -a |   grep   Makefile  \n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"  ls   -l   -h   -a |   grep   Makefile  \" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_pipes_0)
{
    int diff_return = 0;

    system("echo -n \"ls -la | sort -r | head -n 5\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -la | sort -r | head -n 5\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -la | sort -r | head -n 5\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_pipes_1)
{
    int diff_return = 0;

    system("echo -n \"ls -la | grep \"\\.txt$\" | cut -c 1 | wc -l\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -la | grep \"\\.txt$\" | cut -c 1 | wc -l\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -la | grep \"\\.txt$\" | cut -c 1 | wc -l\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_pipes_2)
{
    int diff_return = 0;

    cr_redirect_stderr();
    system("echo -n \"grep \"ERROR\" /var/log/system.log | grep \"apache\" | cut -c 1-19 | sort\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"grep \"ERROR\" /var/log/system.log | grep \"apache\" | cut -c 1-19 | sort\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"grep \"ERROR\" /var/log/system.log | grep \"apache\" | cut -c 1-19 | sort\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_pipes_3)
{
    int diff_return = 0;

    system("echo -n \"grep a Makefile | cut -d . -f2 | sort\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"grep a Makefile | cut -d . -f2 | sort\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"grep a Makefile | cut -d . -f2 | sort\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_multiple_pipes_0)
{
    int diff_return = 0;

    system("echo -n \"ls \\t  -la  |   sort    -r    |   head   -n   5  \n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls \\t  -la  |   sort    -r    |   head   -n   5  \n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls \\\t  -la  |   sort    -r    |   head   -n   5  \" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_multiple_pipes_1)
{
    int diff_return = 0;

    system("echo -n \"\\tls    \\t  -la   |   \\t grep    \"\\.txt$\"   \\t|    cut \\t\\t  -c   1   |      wc    \\t-l\\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"\\tls    \\t  -la   |   \\t grep    \"\\.txt$\"   \\t|    cut \\t\\t  -c   1   |      wc    \\t-l\\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\tls    \\\t  -la   |   \\\t grep    \"\\.txt$\"   \\\t|    cut \\\t\\\t  -c   1   |      wc    \\\t-l\\\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_multiple_pipes_2)
{
    int diff_return = 0;

    cr_redirect_stderr();
    system("echo -n \"     \\t grep \\t \"ERROR\"  \\t /var/log/system.log \\t\\t\\t|\\t grep    \"apache\" \\t|\\t cut    \\t  -c \\t \\t 1-19    \\t |    sort\\t\\t\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"     \\t grep \\t \"ERROR\"  \\t /var/log/system.log \\t\\t\\t|\\t grep    \"apache\" \\t|\\t cut    \\t  -c \\t \\t 1-19    \\t |    sort\\t\\t\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"     \\\t grep \\\t \"ERROR\"  \\\t /var/log/system.log \\\t\\\t\\\t|\\\t grep    \"apache\" \\\t|\\\t cut    \\\t  -c \\\t \\\t 1-19    \\\t |    sort\\\t\\\t\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(pipes_suite, multiple_spaces_multiple_pipes_3)
{
    int diff_return = 0;

    system("echo -n \"\\t\\t\\t\\t\\t\\t\\t\\tgrep\\t\\ta\\t\\tMakefile\\t\\t|\\t\\tcut\\t\\t-d\\t\\t.\\t\\t-f2\\t\\t|\\t\\tsort\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"\\t\\t\\t\\t\\t\\t\\t\\tgrep\\t\\ta\\t\\tMakefile\\t\\t|\\t\\tcut\\t\\t-d\\t\\t.\\t\\t-f2\\t\\t|\\t\\tsort\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\t\\\t\\\t\\\t\\\t\\\t\\\t\\\tgrep\\\t\\\ta\\\t\\\tMakefile\\\t\\\t|\\\t\\\tcut\\\t\\\t-d\\\t\\\t.\\\t\\\t-f2\\\t\\\t|\\\t\\\tsort\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////      outredirections_suite     ///////////////
//////////////////////////////////////////////////////////////

Test(outredirections_suite, ls_outredirection_0)
{
    int diff_return = 0;

    system("echo -n \"ls > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, ls_outredirection_1)
{
    int diff_return = 0;

    system("echo -n \"ls -l > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, ls_outredirection_2)
{
    int diff_return = 0;

    system("echo -n \"ls -la > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -la > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -la > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, ls_outredirection_3)
{
    int diff_return = 0;

    system("echo -n \"ls -lah > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -lah > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lah > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}


Test(outredirections_suite, ls_outredirection_4)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, ls_outredirection_5)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a -h > /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_0)
{
    int diff_return = 0;

    system("echo -n \"ls \\t    >  \\t  \\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls \\t    >  \\t  \\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls \\\t    >  \\\t  \\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_1)
{
    int diff_return = 0;

    system("echo -n \"  \\t ls  \\t  -l   \\t >    \\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"  \\t ls  \\t  -l   \\t >    \\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"  \\\t ls  \\\t  -l   \\\t >    \\\t\\\t\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_2)
{
    int diff_return = 0;

    system("echo -n \"     ls   \\t-la     \\t  >    \\t\\t /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"     ls   \\t-la     \\t  >    \\t\\t /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"     ls   \\\t-la     \\\t  >    \\\t\\\t file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_3)
{
    int diff_return = 0;

    system("echo -n \"\\tls\\t-lah\\t>\\t\\t\\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-lah\\t>\\t\\t\\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\tls\\\t-lah\\\t>\\\t\\\t\\\t\\\t\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}


Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_4)
{
    int diff_return = 0;

    system("echo -n \"\\tls\\t-l\\t-a\\t>\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-l\\t-a\\t>\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\tls\\\t-l\\\t-a\\\t>\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(outredirections_suite, multiple_spaces_tabs_ls_outredirection_5)
{
    int diff_return = 0;

    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >   \\t\\t   /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >   \\t\\t   /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"    ls\\\t    -l    \\\t\\\t-a    \\\t\\\t-h\\\t   >   \\\t\\\t   file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////  double_outredirection_suite   ///////////////
//////////////////////////////////////////////////////////////

Test(double_outredirection_suite, ls_double_outredirection_0)
{
    int diff_return = 0;

    system("echo -n \"ls > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, ls_double_outredirection_1)
{
    int diff_return = 0;

    system("echo -n \"ls -l > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls -l >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, ls_double_outredirection_2)
{
    int diff_return = 0;

    system("echo -n \"ls -la > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -la > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls -la >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -la >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -la > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, ls_double_outredirection_3)
{
    int diff_return = 0;

    system("echo -n \"ls -lah > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -lah > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls -lah >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -lah >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lah > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}


Test(double_outredirection_suite, ls_double_outredirection_4)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls -l -a >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, ls_double_outredirection_5)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a -h > /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls -l -a -h >> /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls -l -a -h >> /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h > file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_0)
{
    int diff_return = 0;

    system("echo -n \"ls \\t    >  \\t  \\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls \\t    >  \\t  \\t/tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"ls \\t    >>  \\t  \\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"ls \\t    >>  \\t  \\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls \\\t    >  \\\t  \\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_1)
{
    int diff_return = 0;

    system("echo -n \"  \\t ls  \\t  -l   \\t >    \\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"  \\t ls  \\t  -l   \\t >    \\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"  \\t ls  \\t  -l   \\t >>    \\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"  \\t ls  \\t  -l   \\t >>    \\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"  \\\t ls  \\\t  -l   \\\t >    \\\t\\\t\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_2)
{
    int diff_return = 0;

    system("echo -n \"     ls   \\t-la     \\t  >    \\t\\t /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"     ls   \\t-la     \\t  >    \\t\\t /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"     ls   \\t-la     \\t  >>    \\t\\t /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"     ls   \\t-la     \\t  >>    \\t\\t /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"     ls   \\\t-la     \\\t  >    \\\t\\\t file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_3)
{
    int diff_return = 0;

    system("echo -n \"\\tls\\t-lah\\t>\\t\\t\\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-lah\\t>\\t\\t\\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"\\tls\\t-lah\\t>>\\t\\t\\t\\t\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-lah\\t>>\\t\\t\\t\\t\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\tls\\\t-lah\\\t>\\\t\\\t\\\t\\\t\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}


Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_4)
{
    int diff_return = 0;

    system("echo -n \"\\tls\\t-l\\t-a\\t>\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-l\\t-a\\t>\\t/tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"\\tls\\t-l\\t-a\\t>>\\t/tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"\\tls\\t-l\\t-a\\t>>\\t/tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"\\\tls\\\t-l\\\t-a\\\t>\\\tfile\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(double_outredirection_suite, multiple_spaces_tabs_ls_double_outredirection_5)
{
    int diff_return = 0;

    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >   \\t\\t   /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >   \\t\\t   /tmp/42sh_output.txt\n\" | ./42sh");
    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >>   \\t\\t   /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"    ls\\t    -l    \\t\\t-a    \\t\\t-h\\t   >>   \\t\\t   /tmp/42sh_output.txt\n\" | ./42sh");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"    ls\\\t    -l    \\\t\\\t-a    \\\t\\\t-h\\\t   >   \\\t\\\t   file\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////        inredirection_suite     ///////////////
//////////////////////////////////////////////////////////////

Test(inredirections_suite, ls_inredirection_0)
{
    int diff_return = 0;

    system("echo -n \"echo ls > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo ls > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_0\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, ls_inredirection_1)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls -l\" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls -l\" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_1\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, ls_inredirection_2)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls -la\" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls -la\" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_2\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, ls_inredirection_3)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls -lah\" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls -lah\" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_3\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}


Test(inredirections_suite, ls_inredirection_4)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls -l -a\" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls -l -a\" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_4\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, ls_inredirection_5)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls -l -a -h\" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls -l -a -h\" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_5\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, multiple_spaces_ls_inredirection_0)
{
    int diff_return = 0;

    system("echo -n \"echo \"ls     \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"ls     \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_6\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, multiple_spaces_ls_inredirection_1)
{
    int diff_return = 0;

    system("echo -n \"echo \"       ls    -l    \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"       ls    -l    \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_7\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, multiple_spaces_ls_inredirection_2)
{
    int diff_return = 0;

    system("echo -n \"echo \"     ls   -la       \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"     ls   -la       \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_8\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, multiple_spaces_ls_inredirection_3)
{
    int diff_return = 0;

    system("echo -n \"echo \"   ls -lah \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"   ls -lah \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_9\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}


Test(inredirections_suite, multiple_spaces_ls_inredirection_4)
{
    int diff_return = 0;

    system("echo -n \"echo \"   ls   -l   -a   \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"   ls   -l   -a   \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_10\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

Test(inredirections_suite, multiple_spaces_ls_inredirection_5)
{
    int diff_return = 0;

    system("echo -n \"echo \"    ls              -l                        -a                        -h             \" > /tmp/tcsh_output.txt\n\" | tcsh");
    system("echo -n \"echo \"    ls              -l                        -a                        -h             \" > /tmp/42sh_output.txt\n\" | ./42sh");
    system("tcsh < /tmp/tcsh_output.txt > /tmp/tcsh_output2.txt\n");
    system("./42sh < /tmp/42sh_output.txt > /tmp/42sh_output2.txt\n");
    diff_return = system("diff /tmp/42sh_output2.txt /tmp/tcsh_output2.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"./42sh < file_11\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt /tmp/42sh_output2.txt /tmp/tcsh_output2.txt diff.txt");
}

//////////////////////////////////////////////////////////////
///////////////   double_inredirection_suite   ///////////////
//////////////////////////////////////////////////////////////

//////////////////////// No thanks :) ////////////////////////

//////////////////////////////////////////////////////////////
///////////////            and_suite           ///////////////
//////////////////////////////////////////////////////////////

Test(and_suite, ls_and_pwd_0)
{
    int diff_return = 0;

    system("echo -n \"ls && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_pwd_1)
{
    int diff_return = 0;

    system("echo -n \"ls -l && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_pwd_2)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_pwd_3)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a -h && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_pwd_4)
{
    int diff_return = 0;

    system("echo -n \"ls -lah && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lah && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lah && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, cat_a_and_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a && pwd\n\" | tcsh 2> /tmp/tcsh_output.txt");
    system("echo -n \"cat a && pwd\n\" | ./42sh 2> /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, cat_Makefile_and_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat Makefile && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"cat Makefile && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat Makefile && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, pwd_and_pwd_and_pwd_and_pwd_and_pwd)
{
    int diff_return = 0;

    system("echo -n \"pwd && pwd && pwd && pwd && pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"pwd && pwd && pwd && pwd && pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd && pwd && pwd && pwd && pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_ls_and_ls_and_ls_and_ls)
{
    int diff_return = 0;

    system("echo -n \"ls && ls && ls && ls && ls\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls && ls && ls && ls && ls\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls && ls && ls && ls && ls\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, ls_and_ls_and_ls_and_ls_and_ls_with_flags)
{
    int diff_return = 0;

    system("echo -n \"ls -lha && ls -lha && ls -lha && ls -lha && ls -lha\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lha && ls -lha && ls -lha && ls -lha && ls -lha\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lha && ls -lha && ls -lha && ls -lha && ls -lha\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(and_suite, cat_a_and_cat_a_and_cat_a_and_cat_a_and_cat_a)
{
    int diff_return = 0;

    system("echo -n \"cat a && cat a && cat a && cat a && cat a\n\" | tcsh 2> /tmp/tcsh_output.txt");
    system("echo -n \"cat a && cat a && cat a && cat a && cat a\n\" | ./42sh 2> /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a && cat a && cat a && cat a && cat a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

////////////////////////////////////////////////////////////
/////////////            or_suite            ///////////////
////////////////////////////////////////////////////////////

Test(or_suite, ls_or_pwd_0)
{
    int diff_return = 0;

    system("echo -n \"ls || pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls || pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_pwd_1)
{
    int diff_return = 0;

    system("echo -n \"ls -l || pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l || pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_pwd_2)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a || pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a || pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_pwd_3)
{
    int diff_return = 0;

    system("echo -n \"ls -l -a -h || pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -l -a -h || pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -l -a -h || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_pwd_4)
{
    int diff_return = 0;

    system("echo -n \"ls -lah || pwd\n\" | tcsh > /tmp/tcsh_output.txt");
    system("echo -n \"ls -lah || pwd\n\" | ./42sh > /tmp/42sh_output.txt");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lah || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_pwd_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || pwd || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || pwd || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || pwd || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_pwd_or_pwd_or_pwd_or_pwd_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || pwd || pwd || pwd || pwd || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || pwd || pwd || pwd || pwd || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || pwd || pwd || pwd || pwd || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_cat_a_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || cat a || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || cat a || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || cat a || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_cat_a_or_cat_a_or_cat_a_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || cat a || cat a || cat a || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || cat a || cat a || cat a || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || cat a || cat a || cat a || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_cat_a_or_cat_a_or_cat_a_or_pwd_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat a || cat a || cat a || cat a || pwd || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || cat a || cat a || cat a || pwd || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || cat a || cat a || cat a || pwd || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_Makefile_and_pwd)
{
    int diff_return = 0;

    system("echo -n \"cat Makefile || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat Makefile || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat Makefile || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, pwd_or_pwd_or_pwd_or_pwd_or_pwd)
{
    int diff_return = 0;

    system("echo -n \"pwd || pwd || pwd || pwd || pwd\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"pwd || pwd || pwd || pwd || pwd\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"pwd || pwd || pwd || pwd || pwd\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_ls_or_ls_or_ls_or_ls)
{
    int diff_return = 0;

    system("echo -n \"ls || ls || ls || ls || ls\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"ls || ls || ls || ls || ls\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls || ls || ls || ls || ls\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, ls_or_ls_or_ls_or_ls_or_ls_with_flags)
{
    int diff_return = 0;

    system("echo -n \"ls -lha || ls -lha || ls -lha || ls -lha || ls -lha\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"ls -lha || ls -lha || ls -lha || ls -lha || ls -lha\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"ls -lha || ls -lha || ls -lha || ls -lha || ls -lha\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_cat_a_or_lslha_or_cat_a_or_cat_a)
{
    int diff_return = 0;

    system("echo -n \"cat a || cat a || ls -lha || cat a || cat a\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || cat a || ls -lha || cat a || cat a\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || cat a || ls -lha || cat a || cat a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}

Test(or_suite, cat_a_or_cat_a_or_cat_a_or_cat_a_or_cat_a)
{
    int diff_return = 0;

    system("echo -n \"cat a || cat a || cat a || cat a || cat a\n\" | tcsh > /tmp/tcsh_output.txt 2>&1");
    system("echo -n \"cat a || cat a || cat a || cat a || cat a\n\" | ./42sh > /tmp/42sh_output.txt 2>&1");
    diff_return = system("diff /tmp/42sh_output.txt /tmp/tcsh_output.txt > diff.txt");

    cr_assert(WEXITSTATUS(diff_return) == 0, "Command \"cat a || cat a || cat a || cat a || cat a\" is different from TCSH");

    system("rm /tmp/tcsh_output.txt /tmp/42sh_output.txt diff.txt");
}
