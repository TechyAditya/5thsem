#include "refactor.h"
int main() {
    setaddr();
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }

    char buffer[MAX];
    int n;
    printf("Enter the message: \n");
    scanf("%[^\n]%*c", buffer);

    send(sockfd, buffer, strlen(buffer), 0);

    close(sockfd);
    return 0;
}