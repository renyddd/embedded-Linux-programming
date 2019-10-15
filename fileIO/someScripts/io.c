#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_LEN 1024

/* 文件的读写拷贝 */
void copy(int fdin, int fdout)
{
    char buff[BUFFER_LEN];
    ssize_t size;

//    printf("file length: %ld\n", lseek(fdin, 0L, SEEK_END));//将文件定位到文件尾部，偏移量为0L
//    lseek(fdin, 0L, SEEK_SET);// 定位到文件开头

    while((size = read(fdin, buff, BUFFER_LEN)) > 0) { //从 fdin 中读取 BUFFER_LEN 个字节存放入  buff 中
//        printf("current: %ld\n", lseek(fdin, 0L, SEEK_CUR));

        if(write(fdout, buff, size) != size) {
            fprintf(stderr, "write error: %s\n", strerror(errno));
            exit(1);
        }
    }
    if(size < 0) {
        fprintf(stderr, "read error:%s\n", strerror(errno));
        exit(1); // 相当于 return 1;
    }
}


void set_fl(int fd, int flag)
{
    int val;

    //获得原来的文件状态标志
    val = fcntl(fd, F_GETFL);
    if(val < 0) {
        perror("fcntl error");
    }

    //增加新的文件状态标志
    val |= flag;

    //重新设置文件状态标志(val 为新的文件状态标志)
    if(fcntl(fd, F_SETFL, val) < 0) {
        perror("fcntl error");
    }
}

void clr_fl(int fd, int flag)
{
    int val;

    val = fcntl(fd, F_GETFL);
    if(val < 0) {
        perror("fcntl error");
    }
    //清除指定的文件状态标志（设置为0）
    val &= ~flag;
    if(fcntl(fd, F_SETFL, val) < 0) {
        perror("fcntl error");
    }
}
