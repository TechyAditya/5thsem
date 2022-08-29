#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#define PORT 8080

struct obj {
    int a, b;
    char op;
};

int main()
{
    int sockfd, n, len;
    struct obj num;
    struct sockaddr_in servaddr, cliaddr;

    if ((sockfd = socket(AF_INET, SOCK_DGRAM, 0)) < 0)
    {
        perror("socket creation failed");
        exit(EXIT_FAILURE);
    }

    memset(&servaddr, 0, sizeof(servaddr));
    memset(&cliaddr, 0, sizeof(cliaddr));

    servaddr.sin_family = AF_INET;
    servaddr.sin_port = htons(PORT);
    servaddr.sin_addr.s_addr = INADDR_ANY;

    if (bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr)) < 0)
    {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }

    len = sizeof(cliaddr);

    recvfrom(sockfd, (struct obj*)&num, sizeof(num), 0, (struct sockaddr*)&cliaddr, &len);
    int result;
    switch (num.op) {
    case '+':
        result = num.a + num.b;
        break;
    case '-':
        result = num.a - num.b;
        break;
    case '*':
        result = num.a * num.b;
        break;
    case '/':
        if (num.b == 0)
            result = -111111;
        else
            result = num.a / num.b;
        break;
    case '%':
        result = num.a % num.b;
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
