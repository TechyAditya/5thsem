#include "../refactor.h"

int main()
{
    printf("Enter two numbers: ");
    scanf("%d %d", &arr[0], &arr[1]);
    printf("Enter the operator: ");
    scanf("\n%c", &op);
    switch (op)
    {
    case '+':
        arr[2] = 1;
        break;
    case '-':
        arr[2] = 2;
        break;
    case '*':
        arr[2] = 3;
        break;
    case '/':
        arr[2] = 4;
        break;
    case '%':
        arr[2] = 5;
        break;

    default:
        arr[2] = 0;
        break;
    }

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    setaddr();

    sendto(sockfd, (const int*)&arr, sizeof(arr), 0, (struct sockaddr*)&servaddr, sizeof(servaddr));
    printf("Object sent\n");

    int result;
    recvfrom(sockfd, (int*)&result, sizeof(int), 0, (struct sockaddr*)&servaddr, &len);
    if (result == -111111)
        printf("Invalid operation\n");
    else
        printf("Result: %d\n", result);
    close(sockfd);

    return 0;
}