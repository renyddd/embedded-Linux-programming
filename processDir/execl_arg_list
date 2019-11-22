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
    const char *arg_list = { NULL };
    
    if ( argc < 2 || strcmp(argv[1], "--help") ==0 )
    {
        printf("用法：./a.out [选项]\n\n \
根据选项的内容，装载不同的子进程。\n\n \
1       计算两数公约数 \n \
2       判断某年是否为闰年 \n \
3       显示时间 \n \
--help  显示此帮助信息\n");
        exit(1);
    }

    // 根据命令行接收到的字符串参数，作出判断
    if (strcmp(argv[1], "1") == 0)
        strcpy(child_name, "gongyueshu");
    else if (strcmp(argv[1], "2") == 0)
        strcpy(child_name, "ifrunnian");
    else if (strcmp(argv[1], "3") == 0)
        strcpy(child_name, "showtime.sh");
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

            execl(child_name, arg_list, NULL);

        default:
            // paretn, do wait job.
            wait(NULL);
            printf("the childPid: %d\n", childPid);
    }

    printf("%s\n", child_name);
    return 0;
}
