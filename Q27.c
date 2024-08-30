/*
============================================================================
Name : 27.c
Author : Patti Sarath
Description : Write a program to execute ls -Rl by the following system calls
a. execl
b. execlp
c. execled. execv
e. execvp
Date: 26th Aug, 2024.
============================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern char **environ;

int main() {
    // Example using execl
    printf("Using execl:\n");
    execl("/bin/ls", "ls", "-Rl", (char *) NULL);

    perror("execl");
    exit(EXIT_FAILURE);

    // Example using execlp
    printf("Using execlp:\n");
    execlp("ls", "ls", "-Rl", (char *) NULL);

    perror("execlp");
    exit(EXIT_FAILURE);

    // Example using execle
    printf("Using execle:\n");
    execle("/bin/ls", "ls", "-Rl", (char *) NULL, environ);

    perror("execle");
    exit(EXIT_FAILURE);

    // Example using execv
    printf("Using execv:\n");
    char *args_v[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", args_v);

    perror("execv");
    exit(EXIT_FAILURE);

    // Example using execvp
    printf("Using execvp:\n");
    char *args_p[] = { "ls", "-Rl", NULL };
    execvp("ls", args_p);

    perror("execvp");
    exit(EXIT_FAILURE);

    return 0;
}
/**
Using execl:
.:
total 688
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Desktop
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Documents
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Aug 29 19:02 Downloads
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:07 example3_file.txt
-rw-r--r-- 1 sarath-patti sarath-patti    30 Aug 26 22:13 example_file.txt
-rw-r--r-- 1 sarath-patti sarath-patti    55 Aug 29 19:05 example.txt
prw-rw-r-- 1 sarath-patti sarath-patti     0 Aug  8 09:16 fifo_first
-rwxrwxr-x 1 sarath-patti sarath-patti 15952 Aug  8 09:03 first
-rw-rw-r-- 2 sarath-patti sarath-patti    66 Aug  8 08:57 first.c
-rw-rw-r-- 2 sarath-patti sarath-patti    66 Aug  8 08:57 hardlink_first
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_0.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_10.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_11.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_12.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_13.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_14.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_15.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_16.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_17.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_18.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_19.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_1.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_20.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_21.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_22.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_23.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_24.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_25.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_26.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_27.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_28.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_29.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_2.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_30.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_31.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_32.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_33.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_34.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_35.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_36.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_37.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_38.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_39.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_3.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_40.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_41.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_42.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_43.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_44.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_45.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_46.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_47.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_48.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_49.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_4.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_50.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_51.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_52.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_53.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_54.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_55.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_56.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_57.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_58.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_59.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_5.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_60.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_61.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_62.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_63.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_64.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_65.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_66.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_67.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_68.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_69.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_6.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_70.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_71.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_72.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_73.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_74.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_7.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_8.txt
-rw-r--r-- 1 sarath-patti sarath-patti     0 Aug 26 21:19 infinite_file_9.txt
-rw-r--r-- 1 sarath-patti sarath-patti    27 Aug 26 21:52 lockfile.dat
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Music
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Pictures
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Public
-rwxrwxr-x 1 sarath-patti sarath-patti 16200 Aug 26 22:13 Q10
-rw-rw-r-- 1 sarath-patti sarath-patti  1866 Aug 29 12:09 Q10.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16288 Aug 26 22:11 Q11
-rw-rw-r-- 1 sarath-patti sarath-patti  2887 Aug 29 11:57 Q11.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16280 Aug 26 21:31 Q12
-rw-rw-r-- 1 sarath-patti sarath-patti  1740 Aug 29 11:54 Q12.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16128 Aug 26 21:33 Q13
-rw-rw-r-- 1 sarath-patti sarath-patti  1201 Aug 29 11:50 Q13.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16256 Aug 26 21:56 Q14
-rw-rw-r-- 1 sarath-patti sarath-patti   967 Aug 26 21:55 Q14.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16024 Aug 26 21:35 Q15
-rw-rw-r-- 1 sarath-patti sarath-patti   515 Aug 29 11:51 Q15.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16400 Aug 26 21:52 Q16a
-rw-rw-r-- 1 sarath-patti sarath-patti  1677 Aug 29 11:44 Q16a.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16312 Aug 26 21:53 Q16b
-rw-rw-r-- 1 sarath-patti sarath-patti  1624 Aug 29 11:42 Q16b.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16280 Aug 26 21:40 Q17
-rw-rw-r-- 1 sarath-patti sarath-patti  1215 Aug 29 11:40 Q17.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16248 Aug 26 21:47 Q18a
-rw-rw-r-- 1 sarath-patti sarath-patti  1163 Aug 29 11:31 Q18a.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16656 Aug 26 21:48 Q18b
-rw-rw-r-- 1 sarath-patti sarath-patti  2879 Aug 29 11:34 Q18b.c
-rwxrwxr-x 1 sarath-patti sarath-patti 15992 Aug 26 21:57 Q19
-rw-rw-r-- 1 sarath-patti sarath-patti   875 Aug 29 12:59 Q19.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16512 Aug 26 21:03 Q2
-rwxrwxr-x 1 sarath-patti sarath-patti 16448 Aug 29 19:00 Q20
-rw-rw-r-- 1 sarath-patti sarath-patti  1833 Aug 29 19:01 Q20.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16208 Aug 29 19:02 Q21
-rw-rw-r-- 1 sarath-patti sarath-patti   997 Aug 29 19:04 Q21.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16288 Aug 29 19:04 Q22
-rw-rw-r-- 1 sarath-patti sarath-patti  1866 Aug 29 19:05 Q22.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16200 Aug 26 22:06 Q23
-rw-rw-r-- 1 sarath-patti sarath-patti  1177 Aug 29 19:06 Q23.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16200 Aug 29 19:07 Q24
-rw-rw-r-- 1 sarath-patti sarath-patti  1357 Aug 29 19:11 Q24.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16256 Aug 26 22:10 Q25
-rw-rw-r-- 1 sarath-patti sarath-patti  2006 Aug 29 19:12 Q25.c
-rwxrwxr-x 1 sarath-patti sarath-patti 15952 Aug 27 15:06 Q26
-rw-rw-r-- 1 sarath-patti sarath-patti   643 Aug 29 19:15 Q26.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16080 Aug 27 15:11 Q27
-rw-rw-r-- 1 sarath-patti sarath-patti  1540 Aug 29 15:30 Q27.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16192 Aug 27 15:13 Q28
-rw-rw-r-- 1 sarath-patti sarath-patti  1660 Aug 29 15:32 Q28.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16368 Aug 27 15:18 Q29
-rw-rw-r-- 1 sarath-patti sarath-patti  2297 Aug 29 15:33 Q29.c
-rw-rw-r-- 1 sarath-patti sarath-patti  1492 Aug 29 12:13 Q2.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16120 Aug 26 21:07 Q3
-rw-rw-r-- 1 sarath-patti sarath-patti  2071 Aug 29 15:38 Q30.c
-rw-rw-r-- 1 sarath-patti sarath-patti  1195 Aug 29 12:17 Q3.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16216 Aug 26 21:09 Q4
-rw-rw-r-- 1 sarath-patti sarath-patti  1724 Aug 29 12:18 Q4.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16160 Aug 26 21:18 Q5
-rw-rw-r-- 1 sarath-patti sarath-patti  1545 Aug 29 12:25 Q5.c
-rwxrwxr-x 1 sarath-patti sarath-patti 16128 Aug 26 21:23 Q6
-rw-rw-r-- 1 sarath-patti sarath-patti  1019 Aug 29 12:33 Q6.c
-rw------- 1 sarath-patti sarath-patti    99 Aug 27 15:19 Q6.c.save
-rwxrwxr-x 1 sarath-patti sarath-patti 16280 Aug 27 10:00 Q9
-rw-rw-r-- 1 sarath-patti sarath-patti  1190 Aug 26 21:38 Q9.c
-rw------- 1 sarath-patti sarath-patti   235 Aug 27 15:19 Q9.c.save
-rw-r--r-- 1 sarath-patti sarath-patti    90 Aug 26 21:47 records.dat
-rwxrwxr-x 1 sarath-patti sarath-patti 15952 Aug  8 09:29 second
-rw-rw-r-- 1 sarath-patti sarath-patti   101 Aug  8 09:28 second.c
drwx------ 4 sarath-patti sarath-patti  4096 Aug  8 08:48 snap
lrwxrwxrwx 1 sarath-patti sarath-patti     7 Aug  8 09:10 symlink_first -> first.c
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Templates
-rw-r--r-- 1 sarath-patti sarath-patti     5 Aug 26 21:40 ticket_file.dat
drwxr-xr-x 2 sarath-patti sarath-patti  4096 Jul 12 19:55 Videos

./Desktop:
total 0

./Documents:
total 0

./Downloads:
total 13860
-rw-rw-r-- 1 sarath-patti sarath-patti    16096 Aug 29 18:57  q20
-rw-rw-r-- 1 sarath-patti sarath-patti    16096 Aug 29 18:57 'q20(1)'
-rw-rw-r-- 1 sarath-patti sarath-patti      772 Aug 29 18:58  q20.c
-rw-rw-r-- 1 sarath-patti sarath-patti      639 Aug 29 19:02  q21.c
-rw-rw-r-- 1 sarath-patti sarath-patti 14148550 Aug  8 09:06 'Slides Folder-20240806.zip'

./Music:
total 0

./Pictures:
total 0

./Public:
total 0

./snap:
total 8
drwxr-xr-x 4 sarath-patti sarath-patti 4096 Aug  8 08:48 firefox
drwxr-xr-x 5 sarath-patti sarath-patti 4096 Aug 22 08:07 snapd-desktop-integration

./snap/firefox:
total 8
drwxr-xr-x 4 sarath-patti sarath-patti 4096 Aug  8 08:48 4698
drwxr-xr-x 4 sarath-patti sarath-patti 4096 Aug  8 08:48 common
lrwxrwxrwx 1 sarath-patti sarath-patti    4 Aug  8 08:48 current -> 4698

./snap/firefox/4698:
total 0

./snap/firefox/common:
total 0

./snap/snapd-desktop-integration:
total 12
drwxr-xr-x 12 sarath-patti sarath-patti 4096 Aug 22 08:07 178
drwxr-xr-x 12 sarath-patti sarath-patti 4096 Jul 12 19:55 83
drwxr-xr-x  3 sarath-patti sarath-patti 4096 Jul 12 19:55 common
lrwxrwxrwx  1 sarath-patti sarath-patti    3 Aug 22 08:07 current -> 178

./snap/snapd-desktop-integration/178:
total 32
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Desktop
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Documents
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Downloads
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Music
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Pictures
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Public
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Templates
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Videos

./snap/snapd-desktop-integration/178/Desktop:
total 0

./snap/snapd-desktop-integration/178/Documents:
total 0

./snap/snapd-desktop-integration/178/Downloads:
total 0

./snap/snapd-desktop-integration/178/Music:
total 0

./snap/snapd-desktop-integration/178/Pictures:
total 0

./snap/snapd-desktop-integration/178/Public:
total 0

./snap/snapd-desktop-integration/178/Templates:
total 0

./snap/snapd-desktop-integration/178/Videos:
total 0

./snap/snapd-desktop-integration/83:
total 32
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Desktop
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Documents
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Downloads
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Music
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Pictures
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Public
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Templates
drwxr-xr-x 2 sarath-patti sarath-patti 4096 Jul 12 19:55 Videos

./snap/snapd-desktop-integration/83/Desktop:
total 0

./snap/snapd-desktop-integration/83/Documents:
total 0

./snap/snapd-desktop-integration/83/Downloads:
total 0

./snap/snapd-desktop-integration/83/Music:
total 0

./snap/snapd-desktop-integration/83/Pictures:
total 0

./snap/snapd-desktop-integration/83/Public:
total 0

./snap/snapd-desktop-integration/83/Templates:
total 0

./snap/snapd-desktop-integration/83/Videos:
total 0

./snap/snapd-desktop-integration/common:
total 0

./Templates:
total 0

./Videos:
total 0
**/
