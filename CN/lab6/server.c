// tcp server
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 1024
#define PORT 8080

int main() {
    int sockfd, connfd, len;
    struct sockaddr_in servaddr, cliaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed...\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_addr.s_addr = htonl(INADDR_ANY);
    servaddr.sin_port = htons(PORT);

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed.\n");
        exit(0);
    }

    len = sizeof(cliaddr);

    connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    char buffer[MAX];
    int n = 0;

    n = recv(connfd, buffer, MAX, 0);
    buffer[n] = '\0';

    printf("From the client: \n");
    printf("%s\n", buffer);

    send(connfd, buffer, strlen(buffer), 0);

    close(sockfd);
    close(connfd);
    return 0;
}