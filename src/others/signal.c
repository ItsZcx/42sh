/*
** EPITECH PROJECT, 2023
** signal
** File description:
** c file for signal
*/

#include "shell.h"

void signal_handler(int signal)
{
    switch (signal) {
        case (SIGSEGV):
            write(2, "Segmentation fault", 18);
            break;
        case (SIGFPE):
            write(2, "Floating exception", 18);
            break;
        case (SIGBUS):
            write(2, "Bus error", 9);
            break;
        case (SIGABRT):
            write(2, "Abort", 5);
            break;
    }
}
