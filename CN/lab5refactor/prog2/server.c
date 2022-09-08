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

    recvfrom(sockfd, (int *)&arr, sizeof(arr), 0, (struct sockaddr*)&cliaddr, &len);
    int result;
    switch (arr[2]) {
    case 1:
        result = arr[0] + arr[1];
        break;
    case 2:
        result = arr[0] - arr[1];
        break;
    case 3:
        result = arr[0] * arr[1];
        break;
    case 4:
        if (arr[1] == 0)
            result = -111111;
        else
            result = arr[0] / arr[1];
        break;
    case 5:
        result = arr[0] % arr[1];
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
