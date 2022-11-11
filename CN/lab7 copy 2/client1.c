#include "refactor.h"
int main() {
    setaddr();

    char buffer[MAX];
    int n;
    printf("Enter the message: \n");
    scanf("%[^\n]%*c", buffer);

    sendto(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));

    close(sockfd);
    return 0;
}