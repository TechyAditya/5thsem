#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080
#define MAX 1024

int main() {
    int sockfd, len;
    struct sockaddr_in servaddr, cliaddr, cliaddr2;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr2, 0, sizeof(cliaddr2));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    len = sizeof(cliaddr);

    // receive from client1
    char buffer[MAX];
    int n = recvfrom(sockfd, buffer, MAX, 0, (struct sockaddr*)&cliaddr, &len);
    buffer[n] = '\0';
    printf("Message from client1: %s\n", buffer);
    // send to client2
    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&cliaddr2, sizeof(cliaddr2));

    close(sockfd);
    return 0;
}