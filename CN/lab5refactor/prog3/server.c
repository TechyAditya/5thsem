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

    recvfrom(sockfd, (struct pass*)&obj, sizeof(obj), 0, (struct sockaddr*)&cliaddr, &len);
    int result;
    switch (obj.op) {
    case '+':
        result = obj.a + obj.b;
        break;
    case '-':
        result = obj.a - obj.b;
        break;
    case '*':
        result = obj.a * obj.b;
        break;
    case '/':
        if (obj.b == 0)
            result = -111111;
        else
            result = obj.a / obj.b;
        break;
    case '%':
        result = obj.a % obj.b;
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
