#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

#define MAX_READ 200
char buffer[MAX_READ];

int main()
{
    int fd;
    fd = open("somefile", O_RDWR);
    read(fd, buffer, MAX_READ);
    printf("The input data(main function hint): \n\n%s\n", buffer);
    return 0;
} 
