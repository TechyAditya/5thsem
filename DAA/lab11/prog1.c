// longest subsequence
#include <stdio.h>
#include <string.h>

int max(int a, int b)
{
    return (a > b) ? a : b;
}

int LongestSubSeq(int arr[], int n)
{
    int dp[n];
    for (int i = 0; i < n; i++)
        dp[i] = 1;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if ((arr[i] == arr[j] + 1) || (arr[i] == arr[j] - 1))
                dp[i] = max(dp[i], dp[j] + 1);
        }
    }
    int result = 1, lb, ub, flag = 1;
    // print longest subsequence from dp
    for (int i = 0; i < n; i++)
        if (result < dp[i]) {
            result = dp[i]; 
        }

    return result;
}

int main()
{
    int arr1[] = { 3, 10, 3, 11, 4, 5, 6, 7, 8, 12 };
    int arr2[] = { 6, 7, 8, 3, 4, 5, 9, 10 };
    int n1 = sizeof(arr1) / sizeof(int);
    int n2 = sizeof(arr2) / sizeof(int);
    printf("\nLength of the increasing subsequence: %d\n", LongestSubSeq(arr1, n1));
    printf("\nLength of the increasing subsequence: %d\n", LongestSubSeq(arr2, n2));
    return 0;
}