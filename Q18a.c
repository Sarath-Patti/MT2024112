/*
============================================================================
Name : 18a.c
Author : Patti Sarath
Description : Write a C, Ansi-style program to perform Record locking.
                       a. Implement write lock
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define RECORD_FILE "records.dat"
#define RECORD_SIZE 30  

void create_records() {
    int fd;
    char records[3][RECORD_SIZE] = {
        "Record 1: Initial data\n",
        "Record 2: Initial data\n",
        "Record 3: Initial data\n"
    };

    fd = open(RECORD_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    for (int i = 0; i < 3; i++) {
        if (write(fd, records[i], RECORD_SIZE) != RECORD_SIZE) {
            perror("write");
            close(fd);
            exit(EXIT_FAILURE);
        }
    }

    close(fd);
    printf("Records created successfully.\n");
}

int main() {
    create_records();
    return 0;
}
/**
Records created successfully.
**/
