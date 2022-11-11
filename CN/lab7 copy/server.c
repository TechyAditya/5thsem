 #include "refactor.h"
int main() {
    setaddr();
    if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) {
        printf("socket bind failed...\n");
        exit(0);
    }

    if ((listen(sockfd, 5)) != 0) {
        printf("Listen failed.\n");
        exit(0);
    }
    len = sizeof(cliaddr);

    int connfd1 = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd1 < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    // receive from client1
    char buffer[MAX];
    int n = recv(connfd1, buffer, MAX, 0);
    buffer[n] = '\0';
    
    recv(connfd1, &n, sizeof(n), 0);

    close(connfd1);

    int connfd2 = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd2 < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    // send to client2
    send(connfd2, buffer, strlen(buffer), 0);

    close(connfd2);

    close(sockfd);
    return 0;
}