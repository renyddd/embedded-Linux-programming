#include<stdio.h>
#include<string.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdlib.h>
#include<unistd.h>

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
            // write
            char buf[1024] = "hello world\n";
//          printf("the length of buf: %ld\n", strlen(buf));
//          The length is 12.
            int returnnum = write(fd, buf, strlen(buf));
            if( returnnum + 1)
            {
                printf("buf=%s\n", buf);
                lseek(fd, -6, SEEK_END);
                char buf2[1024];
                memset(buf2, 0, 1024);
                int returnnum2 = read(fd, buf2, 1024);
                if(returnnum2 + 1)
                    printf("buf2=%s\n", buf2);
            }
            close(fd);
            printf("closed\n");
        }
    return 0;
    }
}
// http://www.voidcn.com/article/p-yxmwsufd-bqv.html
