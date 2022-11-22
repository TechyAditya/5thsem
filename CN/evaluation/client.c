#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

int main()
{
    int sockfd, res;
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);
    
    struct sockaddr_in servaddr;
    int len = sizeof(servaddr);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    sendto(sockfd, (int *)&num, sizeof(num), 0, (struct sockaddr*)&servaddr, len);
    recvfrom(sockfd, (int *)&res, sizeof(res), 0, (struct sockaddr*)&servaddr, &len);

    if (res == 1) {
        printf("%d is a prime number\n", num);
    } else {
        printf("%d is not a prime number\n", num);
    } 
    close(sockfd);
    return 0;
}
