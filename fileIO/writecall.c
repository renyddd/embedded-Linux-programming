#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
// https://www.linuxidc.com/Linux/2016-11/137499.htm

#define MAX_READ 200
#define MAX_WRITE 200
char buffer[MAX_READ];
char wbuffer[MAX_WRITE]="Let write to somefile.\0";

int main()
{
    int fd;
    fd = open("somefile", O_RDWR);
    read(fd, buffer, MAX_READ);
    printf("The file data(main function hint): \n\n%s\n", buffer);

    printf("\nGoing to write...\n");
    write(fd, wbuffer, MAX_WRITE);
    close(fd);

    return 0;
} 
