// Accept two numbers and an operator (from +,-,*,/) and display the result after the operation. 
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter numbers: ");
    double a, b;
    scanf("%lf %lf", &a, &b);
    char op;
    scanf("%c"); //flushing input 
    printf("Enter operator: ");
    scanf("%c", &op);
    switch (op) {
    case '+': printf("%lf + %lf = %lf", a, b, a + b);
        break;
    case '-': printf("%lf - %lf = %lf", a, b, a - b);
        break;
    case '*': printf("%lf * %lf = %lf", a, b, a * b);
        break;
    case '/': if (b != 0)
        printf("%lf / %lf = %lf", a, b, a / b);
            else printf("%lf + %lf = Undefined", a, b);
        break;

    default:
        printf("Invalid operator");
    }

    return 0;
}