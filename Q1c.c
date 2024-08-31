/*
============================================================================
Name : 1b.c
Author : Patti Sarath
Description : Create the following types of a files using (i) shell command (ii) system call
c. FIFO (mkfifo Library Function or mknod system call)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main() {
    const char *fifo_name = "fifo_name";

    if (mkfifo(fifo_name, 0666) == -1) {
        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO created: %s\n", fifo_name);
    return 0;
}

/**
Shell command
mkfifo fifo_name
**/


/**
FIFO created: fifo_name
**/
