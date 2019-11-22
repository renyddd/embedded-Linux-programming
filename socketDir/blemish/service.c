#include <sys/socket.h>
#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <arpa/inet.h>
#include <stdlib.h>

int main()
{
    int fd, rw_fd;
    int ret;
    char buf[128] = {0};
    struct sockaddr_in myaddr;

    fd = socket(PF_INET, SOCK_STREAM, 0);
    if (fd < 0)
    {
        perror("create socket: ");
        exit(1);
    }
    printf("fd = %d", fd);

    // the need in bind()
    myaddr.sin_family = PF_INET; 
    myaddr.sin_port = htons(8888);
    myaddr.sin_addr.s_addr = inet_addr("192.168,0.231");

    ret = bind(fd, (struct sockaddr *) &myaddr, sizeof(struct sockaddr));
    if (ret < 0) {
        perror("bind here: ");
        exit(2);
    }
    

    listen(fd, 5);
    printf("accept before\n");
    rw_fd = accept(fd,  NULL, NULL);
    printf("accept after\n");
    read(rw_fd, buf, 128);
    printf("receive from %s", buf);
    return 0;
}







