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

            execv("gongyueshu", arg_list);

        default:
            // paretn, do wait job.
            wait(NULL);
            printf("the childPid: %d\n", childPid);
    }

    return 0;
}
