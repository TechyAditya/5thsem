#include "refactor.h"
int main() {
    setaddr();
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }
    int ch = 1;
    send(sockfd, &ch, sizeof(int), 0);
    int n;
    recv(sockfd, &n, sizeof(n), 0);

    int arr[n];
    int isEven;
    for (int i = 0; i < n; i++) {
        recv(sockfd, &arr[i], sizeof(arr[i]), 0);

        isEven = (arr[i] % 2 == 0);
        send(sockfd, &isEven, sizeof(isEven), 0);
        printf("%d %s\n", arr[i], isEven ? "is even" : "is odd");
    }
    close(sockfd);
    return 0;
}