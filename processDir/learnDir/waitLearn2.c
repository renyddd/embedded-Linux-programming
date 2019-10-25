#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    pid_t childPid;
    int j;

    for ( j = 1; j < argc; j++)
    {
        switch (fork()) {
            case -1:
                perror("fork()");
                exit(1);

            case 0: // in child process. 
                printf("the PID of the chid %d is: %d\n", j, getpid());
                sleep(3);
                exit(0);

            default:
                printf("I am the parent, my PID is: %d\n", getpid());
                printf("the %d child have been done.\n", wait(NULL));
        }
    }
    
    printf("Parent has finished her jobs, \
            and the line just show once.\n");

    return 0;
}

























