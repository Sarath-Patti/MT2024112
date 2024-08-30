/*
============================================================================
Name : 14.c
Author : Patti Sarath
Description : 14 Write a program to find the type of a file.
a. Input should be taken from command line.
b. program should be able to identify any type of a file.
Date: 25th Aug, 2024.
============================================================================
*/


#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

void print_file_type(mode_t mode) {
    if (S_ISREG(mode)) {
        printf("Regular file\n");
    } else if (S_ISDIR(mode)) {
        printf("Directory\n");
    } else if (S_ISLNK(mode)) {
        printf("Symbolic link\n");
    } else if (S_ISCHR(mode)) {
        printf("Character device\n");
    } else if (S_ISBLK(mode)) {
        printf("Block device\n");
    } else if (S_ISFIFO(mode)) {
        printf("FIFO/pipe\n");
    } else if (S_ISSOCK(mode)) {
        printf("Socket\n");
    } else {
        printf("Unknown file type\n");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <file_path>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    struct stat file_stat;
    if (stat(argv[1], &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    print_file_type(file_stat.st_mode);

    return 0;
}

/**

sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q14 "records.dat"
Regular file

**/
