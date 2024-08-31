/*
============================================================================
Name : 2.c
Author : Patti Sarath
Description :Write a simple program to execute in an infinite loop at the background. Go to /proc directory and
identify all the process related information in the corresponding proc directory.
Date: 29th Aug, 2024.
============================================================================
*/




#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <ctype.h>
void print_process_info(const char *pid) {
    char path[256];
    snprintf(path, sizeof(path), "/proc/%s/stat", pid);
    
    FILE *file = fopen(path, "r");
    if (file == NULL) {
        perror("fopen");
        return;
    }

    char comm[256];
    int pid_num;
    fscanf(file, "%d %s", &pid_num, comm);
    fclose(file);

    printf("Process ID: %d, Command: %s\n", pid_num, comm);
}

int main() {
    while (1) {
        DIR *dir = opendir("/proc");
        if (dir == NULL) {
            perror("opendir");
            exit(EXIT_FAILURE);
        }

        struct dirent *entry;
        while ((entry = readdir(dir)) != NULL) {
            // Check if the directory name is a number
            if (entry->d_type == DT_DIR && isdigit(entry->d_name[0])) {
                print_process_info(entry->d_name);
            }
        }

        closedir(dir);

        // Sleep for a while to avoid high CPU usage
        sleep(10);
    }

    return 0;
}
/**

Process ID: 1, Command: (systemd)
Process ID: 2, Command: (kthreadd)
Process ID: 3, Command: (rcu_gp)
Process ID: 4, Command: (rcu_par_gp)
Process ID: 5, Command: (slub_flushwq)
Process ID: 6, Command: (netns)
Process ID: 8, Command: (kworker/0:0H-events_highpri)
Process ID: 10, Command: (mm_percpu_wq)
Process ID: 11, Command: (rcu_tasks_kthread)
Process ID: 12, Command: (rcu_tasks_rude_kthread)
Process ID: 13, Command: (rcu_tasks_trace_kthread)
Process ID: 14, Command: (ksoftirqd/0)
Process ID: 15, Command: (rcu_preempt)
Process ID: 16, Command: (migration/0)
Process ID: 17, Command: (idle_inject/0)
Process ID: 19, Command: (cpuhp/0)
Process ID: 20, Command: (cpuhp/1)
Process ID: 21, Command: (idle_inject/1)
Process ID: 22, Command: (migration/1)
Process ID: 23, Command: (ksoftirqd/1)
Process ID: 25, Command: (kworker/1:0H-events_highpri)
Process ID: 26, Command: (cpuhp/2)
Process ID: 27, Command: (idle_inject/2)
Process ID: 28, Command: (migration/2)
Process ID: 29, Command: (ksoftirqd/2)
Process ID: 31, Command: (kworker/2:0H-events_highpri)
Process ID: 32, Command: (cpuhp/3)
Process ID: 33, Command: (idle_inject/3)
Process ID: 34, Command: (migration/3)
Process ID: 35, Command: (ksoftirqd/3)
Process ID: 37, Command: (kworker/3:0H-events_highpri)
Process ID: 38, Command: (cpuhp/4)
Process ID: 39, Command: (idle_inject/4)
Process ID: 40, Command: (migration/4)
Process ID: 41, Command: (ksoftirqd/4)
Process ID: 43, Command: (kworker/4:0H-events_highpri)
Process ID: 44, Command: (cpuhp/5)
Process ID: 45, Command: (idle_inject/5)
Process ID: 46, Command: (migration/5)
Process ID: 47, Command: (ksoftirqd/5)
Process ID: 49, Command: (kworker/5:0H-events_highpri)
Process ID: 50, Command: (cpuhp/6)
Process ID: 51, Command: (idle_inject/6)
Process ID: 52, Command: (migration/6)
Process ID: 53, Command: (ksoftirqd/6)
Process ID: 55, Command: (kworker/6:0H-events_highpri)
Process ID: 56, Command: (cpuhp/7)
Process ID: 57, Command: (idle_inject/7)
Process ID: 58, Command: (migration/7)
Process ID: 59, Command: (ksoftirqd/7)
Process ID: 61, Command: (kworker/7:0H-events_highpri)
Process ID: 62, Command: (cpuhp/8)
Process ID: 63, Command: (idle_inject/8)
Process ID: 64, Command: (migration/8)
Process ID: 65, Command: (ksoftirqd/8)
Process ID: 67, Command: (kworker/8:0H-events_highpri)
Process ID: 68, Command: (cpuhp/9)
Process ID: 69, Command: (idle_inject/9)
Process ID: 70, Command: (migration/9)
Process ID: 71, Command: (ksoftirqd/9)
Process ID: 73, Command: (kworker/9:0H-events_highpri)
Process ID: 74, Command: (cpuhp/10)
Process ID: 75, Command: (idle_inject/10)
Process ID: 76, Command: (migration/10)
Process ID: 77, Command: (ksoftirqd/10)
Process ID: 79, Command: (kworker/10:0H-events_highpri)
Process ID: 80, Command: (cpuhp/11)
Process ID: 81, Command: (idle_inject/11)
Process ID: 82, Command: (migration/11)
Process ID: 83, Command: (ksoftirqd/11)
Process ID: 85, Command: (kworker/11:0H-events_highpri)
Process ID: 86, Command: (kdevtmpfs)
Process ID: 87, Command: (inet_frag_wq)
Process ID: 88, Command: (kauditd)
Process ID: 89, Command: (khungtaskd)
Process ID: 91, Command: (oom_reaper)
Process ID: 93, Command: (writeback)
Process ID: 94, Command: (kcompactd0)
Process ID: 95, Command: (ksmd)
Process ID: 97, Command: (khugepaged)
Process ID: 98, Command: (kintegrityd)
Process ID: 99, Command: (kblockd)
Process ID: 100, Command: (blkcg_punt_bio)
Process ID: 101, Command: (kworker/6:1-events)
Process ID: 107, Command: (kworker/9:1-cgroup_destroy)
Process ID: 109, Command: (kworker/11:1-events)
Process ID: 110, Command: (kworker/3:1-events)
Process ID: 111, Command: (tpm_dev_wq)
Process ID: 112, Command: (ata_sff)
Process ID: 113, Command: (md)
Process ID: 114, Command: (edac-poller)
Process ID: 115, Command: (devfreq_wq)
Process ID: 116, Command: (watchdogd)
Process ID: 117, Command: (kworker/6:1H-kblockd)
Process ID: 118, Command: (kswapd0)
Process ID: 119, Command: (ecryptfs-kthread)
Process ID: 120, Command: (kthrotld)
Process ID: 121, Command: (irq/122-aerdrv)
Process ID: 122, Command: (irq/123-aerdrv)
Process ID: 123, Command: (acpi_thermal_pm)
Process ID: 124, Command: (xenbus_probe)
Process ID: 125, Command: (hwrng)
Process ID: 127, Command: (hfi-updates)
Process ID: 130, Command: (mld)
Process ID: 131, Command: (kworker/4:1H-kblockd)
Process ID: 132, Command: (ipv6_addrconf)
Process ID: 139, Command: (kstrp)
Process ID: 141, Command: (zswap-shrink)
Process ID: 147, Command: (charger_manager)
Process ID: 171, Command: (kworker/0:1H-kblockd)
Process ID: 174, Command: (kworker/2:1H-events_highpri)
Process ID: 193, Command: (kworker/10:1H-kblockd)
Process ID: 194, Command: (kworker/9:1H-kblockd)
Process ID: 195, Command: (kworker/3:1H-events_highpri)
Process ID: 196, Command: (kworker/5:1H-events_highpri)
Process ID: 197, Command: (kworker/1:1H-events_highpri)
Process ID: 198, Command: (kworker/11:1H-kblockd)
Process ID: 199, Command: (kworker/7:1H-kblock
**/
