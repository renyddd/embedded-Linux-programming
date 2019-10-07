#include<stdio.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>
#include<string.h>

int main(int argc, char* argv[])
{
    if(argc < 2)
    {
        printf("Please input filename!\n");
        exit(1);
    }
    else
    {
        int fd;
        umask(0000);
        fd = open(argv[1], O_RDWR|O_CREAT, 0666);
        if(fd < 0)
        {
            printf("error\n");
            exit(1);
        }
        else
        {
            printf("success=%d\n", fd);
            // read
            char buf[1024];
            memset(buf, 0, 1024);
// read()  attempts to read up to count bytes from file descriptor fd into the buffer starting at buf.
            int returnnum = read(fd, buf, 1024);
             if(returnnum + 1)
             {
               printf("buf=%s\n", buf);
             }
             else
             {
               printf("error\n");
               exit(1);
             }
            close(fd);
            printf("closed\n");
        }
    return 0;
    }
}
