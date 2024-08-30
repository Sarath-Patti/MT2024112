/*
============================================================================
Name : 21.c
Author : Patti Sarath
Description : Write a program, call fork and print the parent and child process id.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child Process:\n");
        printf("PID: %d\n", getpid());
        printf("Parent PID: %d\n", getppid());
    } else {
        printf("Parent Process:\n");
        printf("PID: %d\n", getpid());
        printf("Child PID: %d\n", pid);
    }

    return 0;
}
/**
Parent Process:
PID: 3811
Child PID: 3812
Child Process:
PID: 3812
Parent PID: 1517
**/
