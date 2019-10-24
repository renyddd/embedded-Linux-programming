#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int create_process (char* program, char** arg_list)
{
    pid_t child_pid;
    child_pid = fork ();
    if (child_pid != 0)
        return child_pid;
    else {
        execvp (program, arg_list);
        abort ();
    }
}



int main ()
{
    char* arg_list[] = {
        "ls",
        "-l",
        "/home/renyddd",
        NULL
    };
    create_process ("ls", arg_list);
    return 0;
}

