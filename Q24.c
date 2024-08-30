/*
============================================================================
Name : 24.c
Author : Patti Sarath
Description :Write a program to create an orphan process.
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
        printf("Child process waiting...\n");

        sleep(30);

        printf("Child process (PID: %d) exiting.\n", getpid());
        exit(EXIT_SUCCESS);
    } else {
        printf("Parent process (PID: %d) exiting.\n", getpid());
        
        exit(EXIT_SUCCESS);
    }

    return 0;
}
/**
Parent process (PID: 3905) exiting.
Child process (PID: 3906) created.
Child process waiting...
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~$ nano Q24.c
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~$ Child process (PID: 3906) exiting.
**/
