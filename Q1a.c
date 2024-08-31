/*
============================================================================
Name : 1a.c
Author : Patti Sarath
Description : Create the following types of a files using (i) shell command (ii) system call
a. soft link (symlink system call)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *target = "example.txt"; 
    const char *linkpath = "symlink_name";      

    if (symlink(target, linkpath) == -1) {
        perror("symlink");
        exit(EXIT_FAILURE);
    }

    printf("Symbolic link created: %s -> %s\n", linkpath, target);
    return 0;
}
/**

Symbolic link created: symlink_name -> example.txt

**/
