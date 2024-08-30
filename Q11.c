/*
============================================================================
Name : 11.c
Author : Patti Sarath
Description :  Write a program to open a file, duplicate the file descriptor and append the file with both the
descriptors and check whether the file is updated properly or not.
a. use dup
b. use dup2
c. use fcntl

Date: 25th Aug, 2024.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILE_NAME "example.txt"
#define TEXT1 "Appended by original FD\n"
#define TEXT2 "Appended by duplicated FD\n"

int main() {
    int fd, fd_dup1, fd_dup2, fd_dup3;
    ssize_t result;

    fd = open(FILE_NAME, O_WRONLY | O_CREAT | O_APPEND, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    fd_dup1 = dup(fd);
    if (fd_dup1 == -1) {
        perror("dup");
        close(fd);
        exit(EXIT_FAILURE);
    }

    fd_dup2 = dup2(fd, fd + 1);  
    if (fd_dup2 == -1) {
        perror("dup2");
        close(fd);
        close(fd_dup1);
        exit(EXIT_FAILURE);
    }

    fd_dup3 = fcntl(fd, F_DUPFD, fd + 2);
    if (fd_dup3 == -1) {
        perror("fcntl");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        exit(EXIT_FAILURE);
    }

    result = write(fd, TEXT1, strlen(TEXT1));
    if (result == -1) {
        perror("write - original");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        close(fd_dup3);
        exit(EXIT_FAILURE);
    }

    result = write(fd_dup1, TEXT2, strlen(TEXT2));
    if (result == -1) {
        perror("write - dup1");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        close(fd_dup3);
        exit(EXIT_FAILURE);
    }

    result = write(fd_dup2, TEXT2, strlen(TEXT2));
    if (result == -1) {
        perror("write - dup2");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        close(fd_dup3);
        exit(EXIT_FAILURE);
    }

    result = write(fd_dup3, TEXT2, strlen(TEXT2));
    if (result == -1) {
        perror("write - dup3");
        close(fd);
        close(fd_dup1);
        close(fd_dup2);
        close(fd_dup3);
        exit(EXIT_FAILURE);
    }

    close(fd);
    close(fd_dup1);
    close(fd_dup2);
    close(fd_dup3);

    printf("File updated successfully. Check '%s' for the appended content.\n", FILE_NAME);

    return 0;
}

/**
File updated successfully. Check 'example.txt' for the appended content.
**/
