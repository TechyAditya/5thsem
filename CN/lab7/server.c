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

    printf("Listening client 1\n");
    int connfd = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    // receive from client1
    int ch;
    recv(connfd, &ch, sizeof(ch), 0);
    if (ch != 0) {
        printf("Client 1 is not connected.\n");
        close(connfd);
        close(sockfd);
        exit(0);
    }

    int n;
    recv(connfd, &n, sizeof(n), 0);

    int isEven, prime;

    int arr[n];
    for (int i = 0; i < n; i++) {
        recv(connfd, &arr[i], sizeof(arr[i]), 0);
    }

    // listen client2
    printf("Listening client 2\n");
    int connfd2 = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd2 < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    // use client2
    recv(connfd2, &ch, sizeof(ch), 0);
    if (ch != 1) {
        printf("Client 2 is not connected.\n");
        close(connfd);
        close(connfd2);
        close(sockfd);
        exit(0);
    }
    send(connfd2, &n, sizeof(n), 0);
    for (int i = 0; i < n; i++) {
        send(connfd2, &arr[i], sizeof(arr[i]), 0);
        recv(connfd2, &isEven, sizeof(isEven), 0);

        send(connfd, &isEven, sizeof(isEven), 0);
    }
    close(connfd2);

    // listen client3
    printf("Listening client 3\n");
    int connfd3 = accept(sockfd, (struct sockaddr*)&cliaddr, &len);
    if (connfd3 < 0) {
        printf("server accept failed.\n");
        exit(0);
    }

    // use client3
    recv(connfd3, &ch, sizeof(ch), 0);
    if (ch != 2) {
        printf("Client 2 is not connected.\n");
        close(connfd);
        close(connfd3);
        close(sockfd);
        exit(0);
    }
    send(connfd3, &n, sizeof(n), 0);
    for (int i = 0; i < n; i++) {
        send(connfd3, &arr[i], sizeof(arr[i]), 0);
        recv(connfd3, &prime, sizeof(prime), 0);

        send(connfd, &prime, sizeof(prime), 0);
    }
    close(connfd3);

    close(connfd);
    close(sockfd);
    return 0;
}