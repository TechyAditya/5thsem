// Write a program that uses a divide-and-conquer algorithm/user defined function for the exponentiation problem of computing an where a > 0 and n is a positive integer.
#include <stdio.h>
int main() {
    int a, n;
    printf("Enter base and exponent: ");
    scanf("%d %d", &a, &n);

    int ans = 1;
    while (n > 0) {
        if (n % 2 == 1) {
            ans *= a;
        }
        a *= a;
        n /= 2;
    }
    printf("Answer: %d", ans);
    return 0;
}