/*
============================================================================
Name : 9.c
Author : Patti Sarath
Description :  9. Write a program to print the following information about a given file.
a. inode
b. number of hard links
c. uid
d. gid
e. size
f. block size
g. number of blocks
h. time of last access
i. time of last modification
j. time of last change
a. use dup
b. use dup2
c. use fcntl

Date: 25th Aug, 2024.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>

void print_file_info(const char *filename) {
    struct stat file_stat;

    if (stat("example.txt", &file_stat) == -1) {
        perror("stat");
        exit(EXIT_FAILURE);
    }

    printf("File: %s\n", "example.txt");
    printf("  Inode number: %ld\n", (long)file_stat.st_ino);
    printf("  Number of hard links: %ld\n", (long)file_stat.st_nlink);
    printf("  User ID: %d\n", file_stat.st_uid);
    printf("  Group ID: %d\n", file_stat.st_gid);
    printf("  Size: %ld bytes\n", (long)file_stat.st_size);
    printf("  Block size: %ld bytes\n", (long)file_stat.st_blksize);
    printf("  Number of blocks: %ld\n", (long)file_stat.st_blocks);

    printf("  Last access time: %s", ctime(&file_stat.st_atime));
    printf("  Last modification time: %s", ctime(&file_stat.st_mtime));
    printf("  Last status change time: %s", ctime(&file_stat.st_ctime));
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <example.txt>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    print_file_info(argv[1]);

    return 0;
}

/**
sarath-patti@sarath-patti-HP-Laptop-15s-fq5xxx:~/.ssh/MT2024112$ ./Q9 "example.txt"
File: example.txt
  Inode number: 532824
  Number of hard links: 1
  User ID: 1000
  Group ID: 1000
  Size: 259 bytes
  Block size: 4096 bytes
  Number of blocks: 8
  Last access time: Thu Aug 29 20:14:47 2024
  Last modification time: Thu Aug 29 20:58:03 2024
  Last status change time: Thu Aug 29 20:58:03 2024
**/
