// Write a program to implementation of 0/1 Knapsack algorithm using greedy method
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
        // calculating profits here
        arr[i].profit = (float)arr[i].value / (float)arr[i].weight;
        arr[i].index = i + 1;
    }
    int capacity;
    printf("Enter capacity:");
    scanf("%d", &capacity);

    // sort by profit descending
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
    // calculate total
    int total = 0;
    for (int i = 0; i < n; i++)
    {
        if (capacity >= arr[i].weight)
        {
            capacity -= arr[i].weight;
            total += arr[i].value;
            arr[i].fraction = 1;
        }
    }
    // sort structure by index
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (arr[i].index > arr[j].index)
            {
                struct item temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // print as table
    printf("Item\tWeight\tValue\tProfit\tInclude\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\t%d\t%d\t%.2f\t%s\n", arr[i].index, arr[i].weight, arr[i].value, arr[i].profit, (int)arr[i].fraction ?  "True" : "False");
    }
    printf("Total value:%d\n", total);
    printf("Total weight remaining:%d\n", capacity);

    return 0;
}