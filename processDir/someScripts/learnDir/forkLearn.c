#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
// #include <<++>>
// #include <<++>>

int main(int argc, char *argv[])
{
    pid_t childPid;

    switch (childPid = fork()) {
        case -1:
            // Handle error
            perror("fork error");
            exit(1);

        case 0:
            // Perform actions specific to child
            printf("I am in child process\n");
            break;

        default:
            // Perform actions specific to parent
            printf("I am in parent process\n");
    }

    printf("This will all be done!\n");
    return 0;

}
