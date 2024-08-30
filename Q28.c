/*
============================================================================
Name : 28.c
Author : Patti Sarath
Description : Write a program to get maximum and minimum real time priority.
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>

int main() {
    int max_priority_fifo, min_priority_fifo;
    int max_priority_rr, min_priority_rr;

    max_priority_fifo = sched_get_priority_max(SCHED_FIFO);
    if (max_priority_fifo == -1) {
        perror("sched_get_priority_max (SCHED_FIFO)");
        exit(EXIT_FAILURE);
    }

    min_priority_fifo = sched_get_priority_min(SCHED_FIFO);
    if (min_priority_fifo == -1) {
        perror("sched_get_priority_min (SCHED_FIFO)");
        exit(EXIT_FAILURE);
    }

    max_priority_rr = sched_get_priority_max(SCHED_RR);
    if (max_priority_rr == -1) {
        perror("sched_get_priority_max (SCHED_RR)");
        exit(EXIT_FAILURE);
    }

    min_priority_rr = sched_get_priority_min(SCHED_RR);
    if (min_priority_rr == -1) {
        perror("sched_get_priority_min (SCHED_RR)");
        exit(EXIT_FAILURE);
    }

    printf("Real-time priority ranges for SCHED_FIFO:\n");
    printf("Max Priority: %d\n", max_priority_fifo);
    printf("Min Priority: %d\n", min_priority_fifo);

    printf("Real-time priority ranges for SCHED_RR:\n");
    printf("Max Priority: %d\n", max_priority_rr);
    printf("Min Priority: %d\n", min_priority_rr);

    return 0;
}
/**
Real-time priority ranges for SCHED_FIFO:
Max Priority: 99
Min Priority: 1
Real-time priority ranges for SCHED_RR:
Max Priority: 99
Min Priority: 1
**/
