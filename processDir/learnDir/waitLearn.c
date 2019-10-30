#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <string.h>
#include <errno.h>

int main(int argc, char *argv[]) {
    int j;

    if ( argc < 2 || strcmp(argv[1], "--help") == 0)
    {
        printf("try again! and type at lease one argument.\n");
        exit(1);
    }

    //setbuf(stdout, NULL);  //Disable one child for each argument

    for (j = 1; j < argc; j++) // Create one child for each argument
    {
        switch (fork()) {
            case -1:
                perror("fork()");
                exit(1);

            case 0: // 因子进程的 fork() 返回 0 而进入此条件
                printf("the PID of child %d is: %d\n", j, getpid());
                printf("My parent is %d\n", getppid());
                sleep(5);
                printf("I (child) wake up!\n\n");
                exit(0);

            default: // 父进程成功生成子进程后，因父进程的 fork() 返回子进程 PID 大于零，因此父进程进入 default，从而执行以下语句，wait 着子进程的释放，以开始新一轮的循环
                printf("I am the parent, my PID: %d\n", getpid());
                // 上面 printf 语句与 wait() 决定了，父进程是先等待还是先输出 PID 内容
                 
                printf("the return value of wait is: %d\n\n", wait(NULL));
         // 若在此处注释 wait() 语句，则子进程的 PPID 将显示为 1，
         // 即成为孤儿进程，被 init 接管
        }
    }

    // Now, just in the parent.
    printf("I (parent) finished my jobs.\n");
    
    return 0;
}

























