#include "refactor.h"

// isPrime function
int isPrime(int n) {
    if (n <= 1) {
        return 0;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    setaddr();
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }
    int ch = 2;
    send(sockfd, &ch, sizeof(int), 0);
    int n;
    recv(sockfd, &n, sizeof(n), 0);

    int arr[n];
    int prime;
    for (int i = 0; i < n; i++) {
        recv(sockfd, &arr[i], sizeof(arr[i]), 0);

        prime = isPrime(arr[i]);
        send(sockfd, &prime, sizeof(prime), 0);
        printf("%d %s\n", arr[i], prime ? "is prime" : "is not prime");
    }
    
    close(sockfd);
    return 0;
}