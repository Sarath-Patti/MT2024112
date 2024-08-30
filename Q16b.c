/*
============================================================================
Name : 16b.c
Author : Patti Sarath
Description : Write a C,Write a program to perform mandatory locking.
              b. Implement read lock
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
    char buffer[100];

    fd = open(LOCK_FILE, O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    lock_file(fd, F_RDLCK);  

    if (read(fd, buffer, sizeof(buffer) - 1) == -1) {
        perror("read");
        unlock_file(fd);
        close(fd);
        exit(EXIT_FAILURE);
    }
    buffer[sizeof(buffer) - 1] = '\0';

    unlock_file(fd);  
    close(fd);

    printf("Read lock applied and released. File content: %s\n", buffer);

    return 0;
}
/**
Read lock applied and released. File content: Writing with a write lock.
**/
