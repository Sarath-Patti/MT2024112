/*
============================================================================
Name : 12.c
Author : Patti Sarath
Description : Write a C,Write a program to find out the opening mode of a file. Use fcntl.
Date: 25th Aug, 2024.
============================================================================
*/




#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

void opening_mode(int fd) {
    int flags = fcntl(fd, F_GETFL);
    if (flags == -1) {
        perror("fcntl error");
        exit(EXIT_FAILURE);
    }
    int accessMode = flags & O_ACCMODE;

    switch (accessMode) {
        case O_RDONLY:
            printf("File is opened in read-only mode.\n");
            break;
        case O_WRONLY:
            printf("File is opened in write-only mode.\n");
            break;
        case O_RDWR:
            printf("File is opened in read-write mode.\n");
            break;
        default:
            printf("Unknown file opening mode.\n");
    }
    if (flags & O_APPEND)
        printf("O_APPEND flag is set.\n");
    if (flags & O_NONBLOCK)
        printf("O_NONBLOCK flag is set.\n");
    if (flags & O_SYNC)
        printf("O_SYNC flag is set.\n");
    if (flags & O_CREAT)
        printf("O_CREAT flag is set.\n");
    if (flags & O_TRUNC)
        printf("O_TRUNC flag is set.\n");
}
    int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Give the correct no of arguments");
        return 1;
    }
    int fd = open(argv[1], O_RDWR | O_APPEND |  O_CREAT, 0644);
    if (fd < 0) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    opening_mode(fd);
    close(fd);
    return 0;
}

/**
File is opened in read-write mode.
O_APPEND flag is set.
**/
