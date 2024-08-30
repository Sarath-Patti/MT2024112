/*
============================================================================
Name : 22.c
Author : Patti Sarath
Description :Write a program, open a file, call fork, and then write to the file by both the child as well as the
parent processes. Check output of the file.
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/types.h>
#include<sys/wait.h>

#define FILE_NAME "example.txt"

int main() {
    int fd;
    pid_t pid;

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    pid = fork();

    if (pid < 0) {
        perror("fork");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (pid == 0) {
        const char *child_msg = "Message from child process\n";
        if (write(fd, child_msg, strlen(child_msg)) != strlen(child_msg)) {
            perror("write - child");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Child wrote to the file.\n");
    } else {
        const char *parent_msg = "Message from parent process\n";
        wait(NULL);
        if (write(fd, parent_msg, strlen(parent_msg)) != strlen(parent_msg)) {
            perror("write - parent");
            close(fd);
            exit(EXIT_FAILURE);
        }
        printf("Parent wrote to the file.\n");
    }

    close(fd);
    return 0;
}
/**
Child wrote to the file.
Parent wrote to the file.
**/
