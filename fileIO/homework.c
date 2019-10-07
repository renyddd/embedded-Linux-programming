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
   memset(buffer, 0, MAX_NUM);
   umask(0000);

   if( (fd = open(argv[1], O_RDWR|O_CREAT, 0644)) >= 0 )
       printf("Open success, fd = %d \n", fd);
   else
   {
       printf("Open failed!\n");
       exit(1);
   }

   strcpy(buffer, "This is My Schoolnumber: 17407110216\0");
   if( write(fd, buffer, strlen(buffer)) + 1)
       printf("\nBuffer=%s\n\n", buffer);
   else
   {
       printf("Write failed!\n");
       exit(1);
   }

   if(! close(fd) )
       printf("\nClosed the file.\n");
   else
   {
       printf("Closed failed!\n");
       exit(1);
   }

   // lseek()
   printf("Let's lseek()\n");

   if( (fd = open(argv[1], O_RDWR|O_CREAT, 0644)) >= 0 )
       printf("Open success, fd = %d \n", fd);
   else
   {
       printf("Open failed!\n");
       exit(1);
   }
   lseek(fd, 0, SEEK_END);
      
   strcpy(buffer, "\nThis is My Schoolnumber: 17407110216\0");
   if( write(fd, buffer, strlen(buffer)) + 1)
       printf("\nBuffer=%s\n\n", buffer);
   else
   {
       printf("Write failed!\n");
       exit(1);
   }
   if(! close(fd) )
       printf("\nClosed the file.\n");
   else
   {
       printf("Closed failed!\n");
       exit(1);
   }

   return 0;
}
