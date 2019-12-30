#include <sys/mman.h>
#include <errno.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <linux/input.h>
#include <unistd.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <time.h>
#include <dirent.h>

int main()              
{                  
    char wav_file_dir[100] = {"./record_repository"};
    DIR *dirp = opendir(wav_file_dir);
    struct dirent *dp;

    int i = 0;
    char *dir_item[50] = { NULL };

    int cnt = 0;

    while ( dp = readdir(dirp) ) {
        printf("%s", dp->d_name);
        printf("\n");
        // strcpy(dir_item[i++], dp->d_name);
        dir_item[i++] = dp->d_name;
    }

    cnt = i;
    i = 0;

    printf("*******************************\n");
    while ( i < cnt ) {
        printf("%s\n", dir_item[i++]);
    }


    closedir(dirp);

    return 0;
} 
