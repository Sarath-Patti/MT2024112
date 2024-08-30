/*
============================================================================
Name : 16a.c
Author : Patti Sarath
Description : Write a C, Ansi-style program to Mandatory locking.
                       a. Implement write lock
Date: 25th Aug, 2024.
============================================================================
*/






#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define LOCK_FILE "lockfile.dat"

void lock_file(int fd, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        exit(EXIT_FAILURE);
    }
}

void unlock_file(int fd) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;  

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        exit(EXIT_FAILURE);
    }
}

int main() {
    int fd;
    char *message = "Writing with a write lock.\n";

    fd = open(LOCK_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    lock_file(fd, F_WRLCK);  

    if (write(fd, message, strlen(message)) == -1) {
        perror("write");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }

    sleep(10);  

    unlock_file(fd);  
    close(fd);

    printf("Write lock applied and released.\n");

    return 0;
}

/**
Write lock applied and released.
**/
