// 3. Let A be an array of n integers a0,a1,... ,an-1 (negative integers are allowed), denoted, by A[i... j], the sub-array ai, ai+1,... ,aj for i≤j. Also let Si-j denote the sum ai + ai+1 +· · · + aj. Write a program by using an udf that must run in O(n2) time to find out the maximum value of Si-j for all the pair i, j with 0 ≤ i ≤ j ≤ n-1. empty sub-array will have sum Si-j = 0. Indeed, if all the elements of A are negative, then one returns 0 as the maximum sub-array sum.
#include <stdio.h>
int maximum_value(int nums[], int l)
{
    int maxsf = nums[0];
    int maxending = 0;
    for (int i = 0; i < l; i++) {
        maxending += nums[i];
        maxsf = maxsf > maxending ? maxsf : maxending;
        if (maxending < 0) {
            maxending = 0;
        }
    }
    return maxsf;
}
int main()
{
    int l, i;
    printf("Enter the length of the array: ");
    scanf("%d", &l);
    int a[l];
    printf("Enter the elements in the array:\n");
    for (i = 0; i < l; i++)
        scanf("%d", &a[i]);

    printf("Max subarray: %d\n", maximum_value(a, l));
}
