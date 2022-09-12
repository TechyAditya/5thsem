// Let A be a list of n (not necessarily distinct) integers. Write a program by using User Defined Function(UDF)s to test whether any item occurs more than n/2 times in A. 
// a) UDF should take O(n2) time and use no additional space.
// b) UDF should take O(n) time and use O(1) additional space.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int findMax(int arr[], int n)
{
    int max = 0;
    for (int i = 0;i < n;++i)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

void algo1(int* arr, int n)
{
    int trigger = 0;
    for (int i = 0;i < n;++i) {
        int num = arr[i];
        int count = 0;
        for (int j = i + 1;j < n;++j)
            if (num == arr[j])
                count++;
        if (count >= n / 2) {
            printf("%d was repeated more than n/2 times\n", num);
            trigger = 1;
        }
    }
    if (!trigger)
        printf("No element was repeated more than n/2 times\n");
}

void algo2(int* arr, int n)
{
    int trigger = 0;
    int max = findMax(arr, n);
    int b[max];
    memset(b, 0, sizeof(b));

    for (int i = 0;i < n;++i)
    {
        int num = arr[i];
        int count = 0;
        b[num]++;
    }
    for (int i = 0;i < max;++i)
        if (b[i] >= n / 2) {
            printf("%d was repeated more than n/2 times\n", i);
            trigger = 1;
        }
    if (!trigger)
        printf("No number was repeated more than n/2 times\n");
}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    printf("O(n^2) approach\n");
    algo1(arr, n);

    printf("O(n) approach\n");
    algo2(arr, n);

    return 0;
}