#include "../refactor.h"
int main()
{
    printf("Enter two numbers: ");
    scanf("%d %d", &obj.a, &obj.b);
    printf("Enter the operator: ");
    scanf("\n%c", &obj.op);

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }
    
    setaddr();

    sendto(sockfd, (const struct obj *)&obj, sizeof(obj), 0, (struct sockaddr *)&servaddr, sizeof(servaddr));
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