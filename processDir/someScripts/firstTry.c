#include<sys/types.h>
#include<unistd.h>
#include<stdlib.h>
#include<stdio.h>

int idata = 111;

int main(int argc, char *argv[])
{
    int istack = 222;
    pid_t childPid;

    switch (childPid = fork()) {
        case -1:
            exit -1;

        case 0:
            idata *= 3;
            istack *= 3;
            break;

        default:
            sleep(3);
            break;
    }

    /* Both parent and child come here */

    printf("PID=%ld %s idata=%d istack=%d\n", (long) getpid(), (childPid == 0) ? "(child)" : "(parent)", idata, istack);

    return 0;
}
