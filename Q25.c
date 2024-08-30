/*
============================================================================
Name : 25.c
Author : Patti Sarath
Description :Write a program to create three child processes. The parent should wait for a particular child (use
waitpid system call).
Date: 26th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define NUM_CHILDREN 3

int main() {
    pid_t pids[NUM_CHILDREN];
    pid_t specific_pid;
    int status;

    for (int i = 0; i < NUM_CHILDREN; ++i) {
        pids[i] = fork();
        
        if (pids[i] < 0) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (pids[i] == 0) {
            printf("Child %d (PID: %d) is running.\n", i, getpid());
            sleep(i + 1);
            printf("Child %d (PID: %d) is exiting.\n", i, getpid());
            exit(EXIT_SUCCESS);
        }
    }

    printf("Parent process (PID: %d) waiting for a specific child.\n", getpid());

    specific_pid = pids[1];

    if (waitpid(specific_pid, &status, 0) == -1) {
        perror("waitpid");
        exit(EXIT_FAILURE);
    }

    if (WIFEXITED(status)) {
        printf("Specific child (PID: %d) exited with status %d.\n", specific_pid, WEXITSTATUS(status));
    } else {
        printf("Specific child (PID: %d) did not exit normally.\n", specific_pid);
    }

    for (int i = 0; i < NUM_CHILDREN; ++i) {
        if (pids[i] != specific_pid) {
            waitpid(pids[i], NULL, 0);
        }
    }

    printf("Parent process (PID: %d) exiting.\n", getpid());

    return 0;
}
/**
Child 0 (PID: 4026) is running.
Parent process (PID: 4025) waiting for a specific child.
Child 1 (PID: 4027) is running.
Child 2 (PID: 4028) is running.
Child 0 (PID: 4026) is exiting.
Child 1 (PID: 4027) is exiting.
Specific child (PID: 4027) exited with status 0.
Child 2 (PID: 4028) is exiting.
Parent process (PID: 4025) exiting.
**/
