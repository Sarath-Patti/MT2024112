/*
============================================================================
Name : 17.c
Author : Patti Sarath
Description : Write a C,Write a program to simulate online ticket reservation. Implement write lock
Write a program to open a file, store a ticket number and exit. Write a separate program, to
open the file, implement write lock, read the ticket number, increment the number and print
the new ticket number then close the file.
Date: 25th Aug, 2024.
============================================================================
*/








#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define TICKET_FILE "ticket_file.dat"
#define INITIAL_TICKET_NUMBER 1000

int main() {
    int fd;
    char buffer[12];
    sprintf(buffer, "%d\n", INITIAL_TICKET_NUMBER);

    fd = open(TICKET_FILE, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }

    if (write(fd, buffer, strlen(buffer)) == -1) {
        perror("write");
        close(fd);
        exit(EXIT_FAILURE);
    }

    close(fd);
    printf("Ticket file initialized with ticket number %d\n", INITIAL_TICKET_NUMBER);

    return 0;
}
/**
Ticket file initialized with ticket number 1000
**/
