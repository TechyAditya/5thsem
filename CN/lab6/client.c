// tcp cliaddrent
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>

#define MAX 1024
#define PORT 6969

int main() {
    int sockfd;
    struct sockaddr_in servaddr, cliaddr;

    if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("socket creation failed.\n");
        exit(0);
    }

    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }

    char buffer[MAX];
    printf("Enter something to send to the server: \n");
    scanf("%[^\n]s", buffer);
    send(sockfd, buffer, strlen(buffer), 0);

    int n = 0;

    n = recv(sockfd, buffer, MAX, 0);
    buffer[n] = '\0';

    printf("From the server: \n");
    printf("%s\n", buffer);

    close(sockfd);
}