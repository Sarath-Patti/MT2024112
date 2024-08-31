/*
============================================================================
Name : 29.c
Author : Patti Sarath
Description : Write a program to get scheduling policy and modify the scheduling policy (SCHED_FIFO,
SCHED_RR).
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <errno.h>
#include <string.h>

void print_policy(int policy) {
    switch (policy) {
        case SCHED_FIFO:
            printf("Current scheduling policy: SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Current scheduling policy: SCHED_RR\n");
            break;
        case SCHED_OTHER:
            printf("Current scheduling policy: SCHED_OTHER\n");
            break;
        default:
            printf("Current scheduling policy: Unknown\n");
            break;
    }
}

void set_policy(int policy) {
    struct sched_param sched_param;
    sched_param.sched_priority = sched_get_priority_max(policy); 

    if (sched_setscheduler(0, policy, &sched_param) == -1) {
        perror("sched_setscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Scheduling policy changed to ");
    print_policy(policy);
}

int main() {
    int current_policy;
    
    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }

    printf("Before changing policy:\n");
    print_policy(current_policy);

    printf("Changing to SCHED_FIFO:\n");
    set_policy(SCHED_FIFO);

    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }
    print_policy(current_policy);

    printf("Changing to SCHED_RR:\n");
    set_policy(SCHED_RR);

    current_policy = sched_getscheduler(0);
    if (current_policy == -1) {
        perror("sched_getscheduler");
        exit(EXIT_FAILURE);
    }
    print_policy(current_policy);

    return 0;
}

/**
[sudo] password for sarath-patti: 
Before changing policy:
Current scheduling policy: SCHED_OTHER
Changing to SCHED_FIFO:
Scheduling policy changed to Current scheduling policy: SCHED_FIFO
Current scheduling policy: SCHED_FIFO
Changing to SCHED_RR:
Scheduling policy changed to Current scheduling policy: SCHED_RR
Current scheduling policy: SCHED_RR
**/
