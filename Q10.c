/*
============================================================================
Name : 10.c
Author : Patti Sarath
Description :Write a program to open a file with read write mode, write 10 bytes, move the file pointer by 10
bytes (use lseek) and write again 10 bytes.
a. check the return value of lseek
b. open the file with od and check the empty spaces in between the data.
Date: 25th Aug, 2024.
============================================================================
*/





#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FILE_NAME "example_file.txt"
#define DATA1 "ABCDEFGHIJ" // 10 bytes of data
#define DATA2 "1234567890" // 10 more bytes of data

int main() {
    int fd;
    off_t offset;
    ssize_t bytes_written;

    // Open the file with read and write permissions (create if it does not exist)
    fd = open(FILE_NAME, O_RDWR | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Write the first 10 bytes of data
    bytes_written = write(fd, DATA1, strlen(DATA1));
    if (bytes_written != strlen(DATA1)) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Move the file pointer 10 bytes forward
    offset = lseek(fd, 10, SEEK_CUR);
    if (offset == (off_t) -1) {
        perror("lseek");
        close(fd);
        exit(EXIT_FAILURE);
    }
    printf("File pointer moved to offset: %ld\n", (long) offset);

    // Write another 10 bytes of data at the new position
    bytes_written = write(fd, DATA2, strlen(DATA2));
    if (bytes_written != strlen(DATA2)) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    // Close the file descriptor
    close(fd);

    printf("File updated successfully. Check '%s' for the data.\n", FILE_NAME);

    return 0;
}

/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q10
File pointer moved to offset: 20
File updated successfully. Check 'example_file.txt' for the data.
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ od -c "example_file.txt"
0000000   A   B   C   D   E   F   G   H   I   J  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   1   2   3   4   5   6   7   8   9   0
0000036
**/
