/*
============================================================================
Name : 5.c
Author : Patti Sarath
Description :Write a program to create five new files with infinite loop. Execute the program in the background
and check the file descriptor table at /proc/pid/fd.
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define NUM_FILES 5
#define SLEEP_DURATION 1  

int main() {
    int fd[NUM_FILES];
    char filename[20];

    printf("Starting file creation program. Files will be created and opened in an infinite loop.\n");

    while (1) {
        for (int i = 0; i < NUM_FILES; ++i) {
            snprintf(filename, sizeof(filename), "file%d.txt", i + 1);
            
            fd[i] = open(filename, O_WRONLY | O_APPEND | O_CREAT, 0644);
            if (fd[i] == -1) {
                perror("open");
                exit(EXIT_FAILURE);
            }
            printf("Opened file: %s with file descriptor: %d\n", filename, fd[i]);
        }

        for (int i = 0; i < NUM_FILES; ++i) {
            if (write(fd[i], "Writing to file\n", 17) == -1) {
                perror("write");
                exit(EXIT_FAILURE);
            }
        }

        for (int i = 0; i < NUM_FILES; ++i) {
            close(fd[i]);
            printf("Closed file descriptor: %d\n", fd[i]);
        }

        sleep(SLEEP_DURATION);
    }

    return 0;
}

/**
Starting file creation program. Files will be created and opened in an infinite loop.
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
Opened file: file1.txt with file descriptor: 3
Opened file: file2.txt with file descriptor: 4
Opened file: file3.txt with file descriptor: 5
Opened file: file4.txt with file descriptor: 6
Opened file: file5.txt with file descriptor: 7
Closed file descriptor: 3
Closed file descriptor: 4
Closed file descriptor: 5
Closed file descriptor: 6
Closed file descriptor: 7
**/
