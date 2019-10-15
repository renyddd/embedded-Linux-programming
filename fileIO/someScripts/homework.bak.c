#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<string.h>
#include<stdlib.h>

#define MAX_NUM 1024
char buffer[MAX_NUM];
//  定义存储换行的缓冲区
char newLineBuffer[5]="\n";

int main(int argc, char* argv[])
// 参数 1 为源码文件名，参数 2 为操作文件名， 参数 3 为要操作的字符串
{
   int fd;
   memset(buffer, 0, MAX_NUM); // 向 buffer 空间写入 0
   umask(0000); // umask 与 mode 共同决定文件的权限

   if( (fd = open(argv[1], O_RDWR|O_CREAT, 0644)) >= 0 )
       printf("Open success, fd = %d \n", fd);
   else
   {
       printf("Open failed!\n");
       exit(1);
   }

/*
// strcpy(buffer, "This is My Schoolnumber: 17407110216\0");
   strcpy(buffer, argv[2]);
   
// 若已向内存空间写入成功，则显示一次字符串
   if( write(fd, buffer, strlen(buffer)) + 1)
       printf("\nBuffer=%s\n\n", buffer);
   else
   {
       printf("Write failed!\n");
       exit(1);
   }

// 第一次写入内容后，添加换行的操作
   if( write(fd, newLineBuffer, strlen(newLineBuffer)) + 1)
       printf("\nInserted an new line.\n");
   else
   {
       printf("Failed to insert an new line.");
       exit(1);
   }

   if(! close(fd) )
       printf("\nClosed the file.\n");
   else
   {
       printf("Closed failed!\n");
       exit(1);
   }
// 文件的第一次关闭
*/

   // lseek()
   printf("Let's lseek()\n************************************\n");

   if( (fd = open(argv[1], O_RDWR|O_CREAT, 0644)) >= 0 )
       printf("Open success, fd = %d \n", fd);
   else
   {
       printf("Open failed!\n");
       exit(1);
   }

// 再次打开文件获取到文件操作符后，通过 lseek 将偏移量移动至文件的最后一个字节   
   lseek(fd, 0, SEEK_END);
      
   strcpy(buffer, argv[2]);

   if( write(fd, buffer, strlen(buffer)) + 1)
       printf("\nBuffer=%s\n\n", buffer);
   else
   {
       printf("Write failed!\n");
       exit(1);
   }
   
// 成功写入 buffer 内容后，追加写入 newLineBuffer 的换行内容
   if( write(fd, newLineBuffer, strlen(newLineBuffer)) + 1)
       printf("\nInserted an new line.\n");
   else
   {
       printf("Failed to insert an new line.");
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
