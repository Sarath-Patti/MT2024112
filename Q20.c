/*
============================================================================
Name : 20.c
Author : Patti Sarath
Description : Find out the priority of your running program. Modify the priority with nice command.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <unistd.h>
#include <sys/resource.h>
#include <stdlib.h>
#include<errno.h>
void print_priority() {
    int nice_value = getpriority(PRIO_PROCESS, 0);
    if (nice_value == -1 && errno != 0) {
        perror("getpriority");
        exit(EXIT_FAILURE);
    }

    printf("Current nice value (priority) of this process: %d\n", nice_value);
}

void set_priority(int new_nice_value) {
    if (setpriority(PRIO_PROCESS, 0, new_nice_value) == -1) {
        perror("setpriority");
        exit(EXIT_FAILURE);
    }

    printf("Priority successfully changed to %d\n", new_nice_value);
}

int main() {
    int new_nice_value;

    print_priority();

    printf("Enter a new nice value (between -20 and 19): ");
    if (scanf("%d", &new_nice_value) != 1) {
        fprintf(stderr, "Invalid input\n");
        exit(EXIT_FAILURE);
    }

    if (new_nice_value < -20 || new_nice_value > 19) {
        fprintf(stderr, "Nice value must be between -20 and 19\n");
        exit(EXIT_FAILURE);
    }

    set_priority(new_nice_value);

    print_priority();

    return 0;
}

/** Current nice value (priority) of this process: 0
Enter a new nice value (between -20 and 19): 6
Priority successfully changed to 6
Current nice value (priority) of this process: 6
**/
