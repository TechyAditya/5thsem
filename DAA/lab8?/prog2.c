// 6.2- activity selection problem
#include <stdio.h>
#include <stdlib.h>
struct activity
{
    int start;
    int finish;
    int index;
};
int main()
{
    int start[] = {1, 3, 0, 5, 8, 5};
    int finish[] = {2, 4, 6, 7, 9, 9};
    int n = sizeof(start) / sizeof(start[0]);
    struct activity arr[n];
    for (int i = 0; i < n; i++)
    {
        arr[i].start = start[i];
        arr[i].finish = finish[i];
        arr[i].index = i;
    }

    // sol:
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].finish > arr[j].finish)
            {
                struct activity temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    printf("Selected activities are:");
    int i = 0;
    printf("%d ", arr[i].index);
    for (int j = 1; j < n; j++)
    {
        if (arr[j].start >= arr[i].finish)
        {
            printf("%d ", arr[j].index);
            i = j;
        }
    }


    return 0;
}