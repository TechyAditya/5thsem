#include "refactor.h"
int main() {
    setaddr();
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }

    int ch = 0;
    send(sockfd, &ch, sizeof(int), 0);

    int n;
    printf("Enter the number of elements: \n");
    scanf("%d", &n);
    send(sockfd, &n, sizeof(n), 0);

    int arr[n];
    printf("Enter the elements: \n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int prime, isEven;
    for (int i = 0; i < n; i++) {
        send(sockfd, &arr[i], sizeof(arr[i]), 0);
    }
    printf("Waiting to process isEven\n");
    for (int i = 0; i < n; i++) {
        recv(sockfd, &isEven, sizeof(isEven), 0);
        printf("%d %s\n", arr[i], isEven ? "is even" : "is odd");
    }
    printf("Waiting to process isPrime\n");
    for (int i = 0; i < n; i++) {
        recv(sockfd, &prime, sizeof(prime), 0);
        printf("%d %s\n", arr[i], prime ? "is prime" : "is not prime");
    }

    close(sockfd);
    return 0;
}