/*
============================================================================
Name : 19.c
Author : Patti Sarath
Description : Write a program to find out time taken to execute getpid system call. Use time stamp counter.
Date: 25th Aug, 2024.
============================================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <unistd.h>
#include <x86intrin.h> // For __rdtsc()

int main() {
    uint64_t start, end;
    pid_t pid;

    // Read the timestamp counter before the system call
    start = __rdtsc();

    // Call getpid() to be measured
    pid = getpid();

    // Read the timestamp counter after the system call
    end = __rdtsc();

    // Output the PID and the time taken
    printf("PID: %d\n", pid);
    printf("Time taken by getpid() in CPU cycles: %lu\n", end - start);

    return 0;
}
/**
PID: 5042
Time taken by getpid() in CPU cycles: 12504
**/
