#include "refactor.h"
int main() {
    setaddr();
    if (connect(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) != 0) {
        printf("connection with the server failed.\n");
        exit(0);
    }
    
    char buffer[MAX];
    int n = recv(sockfd, buffer, strlen(buffer), 0);

    buffer[n] = '\0';
    printf("Message from server: %s\n", buffer);
    
    close(sockfd);
    return 0;
}