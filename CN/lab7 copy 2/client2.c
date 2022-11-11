#include "refactor.h"
int main() {
    setaddr();
    
    char buffer[MAX];
    int n = recvfrom(sockfd, buffer, strlen(buffer), 0, (struct sockaddr*)&servaddr, &len);

    buffer[n] = '\0';
    printf("Message from server: %s\n", buffer);
    
    close(sockfd);
    return 0;
}