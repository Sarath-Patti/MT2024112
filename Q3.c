/*
============================================================================
Name : 3.c
Author : Patti Sarath
Description : Write a program to create a file and print the file descriptor value. Use creat ( ) system call
Date: 26th Aug, 2024.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>   
#include <unistd.h>  

int main() {
    const char *filename = "example3_file.txt"; 
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH; 

    int fd = creat(filename, mode);

    if (fd == -1) {
        perror("creat");  
        exit(EXIT_FAILURE);
    }

    printf("File descriptor for '%s': %d\n", filename, fd);

    if (close(fd) == -1) {
        exit(EXIT_FAILURE);
    }

    return 0;
}
/**

File descriptor for 'example3_file.txt': 3

**/
