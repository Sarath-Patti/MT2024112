/*
============================================================================
Name : 23.c
Author : Patti Sarath
Description : Write a program to create a Zombie state of the running program.
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("fork");
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        printf("Child process (PID: %d) created.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent process (PID: %d) waiting.\n", getpid());
        sleep(30);
        printf("Parent process exiting.\n");
    }

    return 0;
}
/**
Parent process (PID: 3873) waiting.
Child process (PID: 3874) created.
**/
