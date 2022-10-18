// 6.1- implement fractional knapsack problem
#include <stdio.h>
#include <stdlib.h>
struct item
{
    int weight;
    int value;
    float profit;
    int index;
    float fraction;
};
int main()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    struct item arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter weight and value of item %d:", i + 1);
        scanf("%d %d", &arr[i].weight, &arr[i].value);
        arr[i].profit = (float)arr[i].value / (float)arr[i].weight;
        arr[i].index = i + 1;
    }
    int capacity;
    printf("Enter capacity:");
    scanf("%d", &capacity);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].profit < arr[j].profit)
            {
                struct item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity > 0)
        {
            if (capacity >= arr[i].weight)
            {
                capacity -= arr[i].weight;
                total += arr[i].value;
                arr[i].fraction = 1;
            }
            else
            {
                arr[i].fraction = (float)capacity / arr[i].weight;
                total += arr[i].fraction * arr[i].value;
                capacity = 0;
            }
        }
    }
    // print as table
    printf("Item\tWeight\tValue\tProfit\tFraction\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\t%.2f\n", arr[i].index, arr[i].weight, arr[i].value, arr[i].profit, arr[i].fraction);
    }
    printf("Total value:%d\n", total);

    return 0;
}