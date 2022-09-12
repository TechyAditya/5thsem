#include "../refactor.h"
int main()
{
    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    setaddr();

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    len = sizeof(cliaddr);

    recvfrom(sockfd, (int *)&a, sizeof(a), 0, (struct sockaddr*)&cliaddr, &len);
    recvfrom(sockfd, (int *)&b, sizeof(b), 0, (struct sockaddr*)&cliaddr, &len);
    recvfrom(sockfd, (char *)&op, sizeof(op), 0, (struct sockaddr*)&cliaddr, &len);

    int result;
    switch (op) {
    case '+':
        result = a + b;
        break;
    case '-':
        result = a - b;
        break;
    case '*':
        result = a * b;
        break;
    case '/':
        if (b == 0)
            result = -111111;
        else
            result = a / b;
        break;
    case '%':
        result = a % b;
        break;
    default:
        printf("Invalid operator\n");
        result = -111111;
        break;
    }

    sendto(sockfd, (const int*)&result, sizeof(result), 0, (const struct sockaddr*)&cliaddr, sizeof(cliaddr));
    printf("Result sent.\n");

    return 0;
}
