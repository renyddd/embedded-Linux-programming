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
        printf("try again!\n");
        exit(1);
    }

    setbuf(stdout, NULL);  //Disable one child for each argument

    for (j = 1; j < argc; j++) // Create one child for each argument
    {
        switch (fork()) {
            case -1:
                perror("fork()");break;

            case 0:
                printf("the PID of child %d is: %d\n", j, getpid());
                break;

            default: 
                printf("I am in my parent.\n");
                break;
        }
    }

    numDead = 0;

    for (;;)  // Parent waits for each child to exit.
    {
       childPid = wait(NULL);
       if (childPid == -1)
       {
           if (errno == ECHILD)
           {
               printf("No more child\n");
               exit(EXIT_SUCCESS);
           }
           else
           {
               perror("other wrong");
               exit(1);
           }
       }
        numDead++;
        printf("wiat() returned child PID is %d\n", childPid);
    }

    return 0;

}

























