#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

int 
main(int argc, char *argv[])
{
    int fd;
    if ( fd = open(argv[1], O_RDWR) >= 0)
    {
        printf("no possible.\n");
    }
    else
    {
        perror(argv[1]);
        exit(-1);
    }
    return 0;
}

