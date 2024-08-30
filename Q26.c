/*
============================================================================
Name : 26.c
Author : Patti Sarath
Description : Write a program to execute an executable program.
a. use some executable program
b. pass some input to an executable program.
Date: 26th Aug, 2024.
============================================================================
*/

#include <stdio.h>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <name>\n", argv[0]);
        return 1;
    }

    printf("Hello, %s!\n", argv[1]);
    return 0;
}
/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~$ ./Q26 "./Q25"
Hello, ./Q25!
**/
