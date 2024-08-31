/*
============================================================================
Name : 6.c
Author : Patti Sarath
Description : Write a program to take input from STDIN and display on STDOUT. Use only read/write system calls
Date: 29th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    ssize_t bytesRead, bytesWritten;

    while ((bytesRead = read(STDIN_FILENO, buffer, BUFFER_SIZE)) > 0) {
        bytesWritten = write(STDOUT_FILENO, buffer, bytesRead);

        if (bytesWritten != bytesRead) {
            perror("write");
            exit(EXIT_FAILURE);
        }
    }

    if (bytesRead == -1) {
        perror("read");
        exit(EXIT_FAILURE);
    }

    return 0;
}
/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q6 
pavan
pavan
sarath
sarath
**/
