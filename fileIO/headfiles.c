#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM 1024
char buffer[MAX_NUM];

int main(int argc, char* argv[])
{
   int fd;
   fd = open(argv[1], O_RDWR|O_CREAT, 0666);
   if( fd >= 0 )
       printf("open success, fd = %d \n", fd);


   return 0;
}
