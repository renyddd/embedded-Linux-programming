#include <stdio.h>  
#include <unistd.h>
#include <stdlib.h>  
#include <string.h>  
#include <errno.h>  
#include <sys/types.h>  
#include <sys/socket.h>  
#include <arpa/inet.h>
#include <netinet/in.h>  

#define PORTNUM 8888
#define MAXLEN 4096

void error_die(const char *sc)
{
    perror(sc);
    exit(1);
}

void print_len(const char *sc)
{
    printf("===== %s =====\n", sc);
}

int main(int argc, char *argv[])
{
    int socket_fd, connect_fd;
    struct sockaddr_in servaddr, clientaddr;
    char buff[MAXLEN];
    int n;
    socklen_t sizelen;

    if ( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
        error_die("create socket");
    print_len("create socket");

    // 初始化
    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY); //自动获取本机 IP
    servaddr.sin_port = htons(PORTNUM);

    // note sizeof
    if ( bind(socket_fd, (struct sockaddr *) &servaddr, sizeof(struct sockaddr)) == -1)
        error_die("bind error");
    print_len("bound done");

    if ( listen(socket_fd, 10) == -1)
        error_die("listen error");
    print_len("listened done");

    print_len("waiting fo client's request");

    sizelen = sizeof(struct sockaddr_in);

    while (1) {
        // 阻塞
        if ((connect_fd = accept(socket_fd, (struct sockaddr *)&clientaddr, &sizelen)) == -1)
            error_die("connect error");
        
        print_len("accept the client");
        printf("\r\nConnect from %s : %d\r\n", inet_ntoa(clientaddr.sin_addr), ntohs(clientaddr.sin_port));
        //printf("\r\nConnect from %#x : %#x\r\n", inet_ntoa( ntohl(clientaddr.sin_addr.s_addr)), ntohs(clientaddr.sin_port));

        if (!fork()) 
        {
            // child
            n = recv(connect_fd, buff, MAXLEN, 0);
        
            buff[n] = '\0';
            printf("recv from client: %s\n", buff);

            close(connect_fd);

            exit(0);
        }
        close(connect_fd);
    }

    close(socket_fd);
    return 0;
}
