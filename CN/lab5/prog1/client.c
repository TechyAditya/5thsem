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
    int sockfd, n, len;
    
    int a,b;
    char op;

    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter the operator: ");
    scanf("\n%c", &op);
    
    struct sockaddr_in servaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    memset(&servaddr, 0, sizeof(servaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    sendto(sockfd, (const int *)&a, sizeof(a), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    sendto(sockfd, (const int *)&b, sizeof(b), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    sendto(sockfd, (const char *)&op, sizeof(op), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
    printf("Object sent\n");

    int result;
    recvfrom(sockfd, (int *)&result, sizeof(int), 0, (struct sockaddr *)&servaddr, &len);
    if(result == -111111)
        printf("Invalid operation\n");
    else
        printf("Result: %d\n", result);
    close(sockfd);

    return 0;
} 