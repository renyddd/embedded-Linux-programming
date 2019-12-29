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

int main()              
{                  
    struct tm * mytime;
    time_t tmp;    
    char wav_file_name[20];
    // 必须以这种形式声明吗?


    time(&tmp);
    mytime = localtime(&tmp);
    printf("mytime got the value: %d_%d_%d.wav\n", mytime->tm_hour,mytime->tm_min, mytime->tm_sec);

    sprintf(wav_file_name, "%d_%d_%d.wav", mytime->tm_hour,mytime->tm_min, mytime->tm_sec);
    // sprintf(wav_file_name, "%d", 666);

    printf("going to show wav_file_name: ");
    printf("%s\n", wav_file_name);

    return 0;                                                                                    
} 
