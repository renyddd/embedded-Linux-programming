#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <<++>>
// #include <<++>>

int main(int argc, char *argv[])
{
    switch (fork()) {
        case -1: // Handle error
            perror("fork error");
            exit(1);

        case 0:  // Perform actions specific to child
            printf("This is child process, PID is %d\n", getpid());
            printf("My PPID is %d\n", getppid());
            break;

        default: // Perform actions specific to parent
            printf("This is parent process, PID is %d\n", getpid());
    }

    printf("This will be shown in both parent and child! %d\n\n", getpid());

    return 0;
}
