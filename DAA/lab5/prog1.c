// 1. Write a program by using an user defined function for computing √n for any positive integer n. Besides assignment and comparison, your algorithm may only use the four basic arithmetical operations.
#include <stdio.h>
typedef unsigned long long ll;
int main()
{
    ll n;
    scanf("%llu", &n);
    ll l = 0, r = n;
    while (l < r)
    {
        ll mid = (l + r) / 2;
        if (mid * mid <= n)
            l = mid + 1;
        else
            r = mid;
    }
    printf("%llu\n", l - 1);
    
    return 0;
}
