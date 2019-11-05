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
    
    char child_name[20] = {0};
    char *arg_list[]={
         "ls",
        "-lh",
        "--color=tty",
        "./",
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

//            execv(child_name, arg_list);
    //O        execl(child_name, "");
            execvp("ls", arg_list);


        default:
            // paretn, do wait job.
            wait(NULL);
            printf("the childPid: %d\n", childPid);
    }

    printf("%s\n", child_name);
    return 0;
}
