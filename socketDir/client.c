#include<stdio.h>  
#include<stdlib.h>  
#include<unistd.h>
#include<string.h>  
#include<errno.h>  
#include<sys/types.h>  
#include<sys/socket.h>  
#include<netinet/in.h>  
#include<arpa/inet.h>

#define MAXLEN 4096

int main(int argc, char *argv[])
{
    int socket_fd;
    char sendmsg[MAXLEN];
    struct sockaddr_in servaddr;
    int conf;
    int lensize;

    if ( argc != 2 )
    {
        printf("usage: ./client <ipaddress>\n");
        exit(0);
    }

    if ( (socket_fd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
    {
        perror("create socket ");
        exit(1);
    }

    memset(&servaddr, 0, sizeof(struct sockaddr_in));
    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(8888);
    if ( inet_pton(AF_INET, argv[1], &servaddr.sin_addr) == -1)
    {
        perror("inet_pton error ");
        exit(1);
    }
    //
    lensize =  sizeof(struct sockaddr_in);
    if ( (conf=connect(socket_fd, (struct sockaddr *) &servaddr, lensize)) == -1)
    {
        perror("connect error ");
        exit(1);
    }
    printf("\n%d",conf);
    printf("send msg to service: \n");
    fgets(sendmsg, MAXLEN, stdin);

    if ( write(socket_fd, sendmsg, strlen(sendmsg)) == -1)
    {
        perror("write error ");
        exit(1);
    }

    close(socket_fd);
    return 0;
}
