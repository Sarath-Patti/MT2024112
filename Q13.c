/*
============================================================================
Name : 13.c
Author : Patti Sarath
Description : Write a C,Write a program to wait for a STDIN for 10 seconds using select. Write a proper print statement to
verify whether the data is available within 10 seconds or not
 
Date: 25th Aug, 2024.
============================================================================
*/



#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/select.h>
#include <errno.h>

int main() {
    fd_set read_fds;
    struct timeval timeout;
    int result;

    FD_ZERO(&read_fds);
    FD_SET(STDIN_FILENO, &read_fds);

    timeout.tv_sec = 10;
    timeout.tv_usec = 0;

    result = select(STDIN_FILENO + 1, &read_fds, NULL, NULL, &timeout);

    if (result == -1) {
        perror("select");
        exit(EXIT_FAILURE);
    } else if (result == 0) {
        printf("No data available on STDIN within 10 seconds.\n");
    } else {
        if (FD_ISSET(STDIN_FILENO, &read_fds)) {
            printf("Data is available on STDIN.\n");
        } else {
            printf("Unexpected result: No data available.\n");
        }
    }

    return 0;
}
/**
No data available on STDIN within 10 seconds.
**/
