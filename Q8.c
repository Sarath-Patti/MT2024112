/*
============================================================================
Name : 8.c
Author : Patti Sarath
Description : Write a program to open a file in read only mode, read line by line and display each line as it is read.
Close the file when end of file is reached.
Date: 30th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    const char *path = "text.txt";  

    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[1024]; 

    while (fgets(line, sizeof(line), file) != NULL) {
        printf("%s", line);
    }

    fclose(file);

    return EXIT_SUCCESS;
}
/**
Hello world
SS Program
**/
