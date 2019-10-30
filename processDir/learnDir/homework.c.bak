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
    char *arg_list[] = {
        NULL
    };
    
    if ( argc < 2 || strcmp(argv[1], "--help") ==0 )
    {
        printf("some help\n");
        exit(1);
    }
    // 或是使用系统调用 getopt
    if (strcmp(argv[1], "1") == 0)
        strcpy(child_name, "gongyueshu");
    else if (strcmp(argv[1], "2") == 0)
        strcpy(child_name, "ifrunnian");
    else if (strcmp(argv[1], "3") == 0)
        strcpy(child_name, "showtime");
    else
        exit(1);

    switch ( childPid = fork() ) {
        case -1:
            perror("fork");
            exit(1);

        case 0:
            // child, do execvp job.
            printf("the PID of the child: %d\n", getpid());
            printf("My parent is %d\n", getppid());

            execv(child_name, arg_list);

        default:
            // paretn, do wait job.
            wait(NULL);
            printf("the childPid: %d\n", childPid);
    }

    printf("%s\n", child_name);
    return 0;
}
