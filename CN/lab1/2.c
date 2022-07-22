// Use the recursion to find the factorial of a number
#include <stdio.h>
#include <stdlib.h>
int fact(int num){
    if(num > 1)
        return num * fact(num - 1);
    else 
        return num;
}
int main()
{
    printf("Enter number: ");
    int num;
    scanf("%d", &num);
    printf("Factorial of %d is %d\n", num, fact(num));

    return 0;
}