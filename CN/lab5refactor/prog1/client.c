#include "../refactor.h"
int main()
{
    printf("Enter two numbers: ");
    scanf("%d %d", &a, &b);
    printf("Enter the operator: ");
    scanf("\n%c", &op);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    setaddr();

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