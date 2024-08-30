/*
============================================================================
Name : 18b.c
Author : Patti Sarath
Description : Write a C, Ansi-style program to perform Record locking.
                       b. Implement read lock
Date: 25th Aug, 2024.
============================================================================
*/






#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

#define RECORD_FILE "records.dat"
#define RECORD_SIZE 30

void lock_record(int fd, off_t offset, int length, int lock_type) {
    struct flock lock;
    lock.l_type = lock_type;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = length;

    if (fcntl(fd, F_SETLKW, &lock) == -1) {
        perror("fcntl - lock");
        exit(EXIT_FAILURE);
    }
}

void unlock_record(int fd, off_t offset, int length) {
    struct flock lock;
    lock.l_type = F_UNLCK;
    lock.l_whence = SEEK_SET;
    lock.l_start = offset;
    lock.l_len = length;

    if (fcntl(fd, F_SETLK, &lock) == -1) {
        perror("fcntl - unlock");
        exit(EXIT_FAILURE);
    }
}

void read_record(int fd, int record_number) {
    off_t offset = record_number * RECORD_SIZE;
    char buffer[RECORD_SIZE + 1];

    lock_record(fd, offset, RECORD_SIZE, F_RDLCK);

    lseek(fd, offset, SEEK_SET);
    if (read(fd, buffer, RECORD_SIZE) != RECORD_SIZE) {
        perror("read");
        unlock_record(fd, offset, RECORD_SIZE);
        exit(EXIT_FAILURE);
    }
    buffer[RECORD_SIZE] = '\0';
    printf("Read Record %d: %s", record_number + 1, buffer);

    unlock_record(fd, offset, RECORD_SIZE);
}

void write_record(int fd, int record_number, const char *data) {
    off_t offset = record_number * RECORD_SIZE;

    lock_record(fd, offset, RECORD_SIZE, F_WRLCK);

    lseek(fd, offset, SEEK_SET);
    if (write(fd, data, RECORD_SIZE) != RECORD_SIZE) {
        perror("write");
        unlock_record(fd, offset, RECORD_SIZE);
        exit(EXIT_FAILURE);
    }

    unlock_record(fd, offset, RECORD_SIZE);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <record_number> <data>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    int record_number = atoi(argv[1]) - 1;
    if (record_number < 0 || record_number > 2) {
        fprintf(stderr, "Invalid record number. Must be 1, 2, or 3.\n");
        exit(EXIT_FAILURE);
    }

    int fd = open(RECORD_FILE, O_RDWR);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    char data[RECORD_SIZE];
    snprintf(data, sizeof(data), "%-19s\n", argv[2]); 
    write_record(fd, record_number, data);

    read_record(fd, record_number);

    close(fd);
    return 0;
}

/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q18b 1 "records.dat"
Read Record 1: records.dat   
**/
