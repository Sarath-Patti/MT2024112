/*
============================================================================
Name : 4.c
Author : Patti Sarath
Description : Write a program to open an existing file with read write mode. Try O_EXCL flag also.
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *filename = argv[1];
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead;
    int fd;

    fd = open(filename, O_RDWR); 
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    printf("Successfully opened file: %s\n", filename);

    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0'; 
        printf("%s", buffer);
    }

    if (bytesRead == -1) {
        perror("read");
        close(fd);
        exit(EXIT_FAILURE);
    }

    if (close(fd) == -1) {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}

/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q4 "records.dat"
Successfully opened file: records.dat
records.dat 
**/


