
/*
============================================================================
Name : 7.c
Author : Patti Sarath
Description :Write a program to copy file1 into file2 ($cp file1 file2). 
Date: 30th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFFER_SIZE 1024

void copy_file(const char *source_path, const char *dest_path) {
    int src_fd, dest_fd;
    char buffer[BUFFER_SIZE];
    ssize_t bytes_read, bytes_written;

    src_fd = open(source_path, O_RDONLY);
    if (src_fd == -1) {
        perror("Error opening source file");
        exit(EXIT_FAILURE);
    }

    dest_fd = open(dest_path, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (dest_fd == -1) {
        perror("Error opening destination file");
        close(src_fd);
        exit(EXIT_FAILURE);
    }

    while ((bytes_read = read(src_fd, buffer, sizeof(buffer))) > 0) {
        bytes_written = write(dest_fd, buffer, bytes_read);
        if (bytes_written != bytes_read) {
            perror("Error writing to destination file");
            close(src_fd);
            close(dest_fd);
            exit(EXIT_FAILURE);
        }
    }

    if (bytes_read == -1) {
        perror("Error reading source file");
    }

    if (close(src_fd) == -1) {
        perror("Error closing source file");
    }
    if (close(dest_fd) == -1) {
        perror("Error closing destination file");
    }
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <source_file> <destination_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    const char *source_path = argv[1];
    const char *dest_path = argv[2];

    copy_file(source_path, dest_path);

    printf("File copied from %s to %s\n", source_path, dest_path);
    return 0;
}
/**

sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q7 "example.txt" "records.dat"
File copied from example.txt to records.dat

**/
