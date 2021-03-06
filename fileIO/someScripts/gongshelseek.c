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
        fd = open(argv[1], O_RDWR|O_CREAT, 0644);
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
            
            if( write(fd, buf, strlen(buf)) + 1)
            {
                printf("buf=%s\n", buf);
                // lseek
                lseek(fd, 6, SEEK_SET);
                char buf2[1024];
                memset(buf2, 0, 1024);
                
                if(read(fd, buf2, 1024) + 1)
                    printf("buf2=%s\n", buf2);
            }
            close(fd);
            printf("closed\n");
        }
    return 0;
    }
}
