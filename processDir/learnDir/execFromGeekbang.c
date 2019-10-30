#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
// Reference https://time.geekbang.org/column/article/90855

int main()
{
    pid_t child_pid;

    char *arg_list[] = {
        "ls",
        "-lh",
        "--color=tty",
        "./",
        NULL
    };

    child_pid = fork ();

    if ( child_pid )
        return child_pid;
    else {
        execvp ("ls", arg_list);
    }

    return 0;
}
