#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[])
{
    int numDead;  // Number of children so far waited for
    pid_t childPid;
    int j;

    if ( argc < 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("try again! and type at lease one argument.\n");
        exit(1);
    }

    setbuf(stdout, NULL);  //Disable one child for each argument

    for (j = 1; j < argc; j++) // Create one child for each argument
    {
        switch (fork()) {
            case -1:
                perror("fork()");
                exit(1);

            case 0:
                printf("the PID of child %d is: %d\n", j, getpid());
                printf("My parent is %d\n", getppid());
                sleep(5);
                printf("I (child) wake up!\n");
                exit(0);

            default: 
                printf("I am the parent, my PID: %d\n", getpid());
                wait(NULL);
         // 若在此处注释 wait() 语句，则子进程的 PPID 将显示为 1，
         // 即成为孤儿进程，被 init 接管
        }
    }

    // Now in the parent.
    //
    printf("I (parent) finished my jobs.\n");
    
    return 0;

}

























