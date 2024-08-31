/*
============================================================================
Name : 1b.c
Author : Patti Sarath
Description : Create the following types of a files using (i) shell command (ii) system call
b. hard link (link system call)
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() {
    const char *target = "example.txt"; // Target file
    const char *linkpath = "hardlink_name";       // Hard link name

    if (link(target, linkpath) == -1) {
        perror("link");
        exit(EXIT_FAILURE);
    }

    printf("Hard link created: %s -> %s\n", linkpath, target);
    return 0;
}

/**
 shell command 
ln -s "example.txt" symlink_name
**/




/**
Hard link created: hardlink_name -> example.txt
**/
