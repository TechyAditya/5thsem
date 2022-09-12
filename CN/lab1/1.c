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
    case '+': printf("%.2lf + %.2lf = %.2lf\n", a, b, a + b);
        break;
    case '-': printf("%.2lf - %.2lf = %.2lf\n", a, b, a - b);
        break;
    case '*': printf("%.2lf * %.2lf = %.2lf\n", a, b, a * b);
        break;
    case '/': if (b != 0)
        printf("%.2lf / %.2lf = %.2lf\n", a, b, a / b);
            else printf("%.2lf + %.2lf = Undefined\n", a, b);
        break;

    default:
        printf("Invalid operator");
    }

    return 0;
}