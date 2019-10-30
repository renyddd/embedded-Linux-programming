#include <stdio.h>
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
    pid_t waitReturnNum;

    char *arg_list[] = {
        NULL
    };

    switch ( childPid = fork() ) {
        case -1:
            perror("fork");
            exit(1);

        case 0:
            // child, do execvp job.
            printf("the PID of the child: %d\n", getpid());
            printf("My parent is %d\n", getppid());

            execv("hello", arg_list);

            // if run the next line.
            printf("*********************************** Just a test line.\n");
            // NO
            // The exec() family of functions replaces the current process image with a new process image.

        default:
            // paretn, do wait job.
            waitReturnNum =  wait(NULL);
            printf("\nParent after wait, the waitReturnNum:%d\n", waitReturnNum); 
            printf("the childPid: %d\n", childPid);
    }

    return 0;
}
