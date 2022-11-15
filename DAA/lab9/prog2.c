// activity selection problem

#include<stdio.h>
#include<stdlib.h>
#include <string.h>

void display(int a[], int size)
{
    for (int i = 0; i < size; i++)
        printf("%d ", a[i]);
    printf("\n");
}

void swapChar(char* x, char* y)
{
    char tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void swap(int* x, int* y)
{
    int tmp;
    tmp = *x;
    *x = *y;
    *y = tmp;
}

void sortingInterval(char character[], int start[], int end[], int intervaldiff[], int size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (intervaldiff[j] > intervaldiff[j + 1])
            {
                swap(&intervaldiff[j], &intervaldiff[j + 1]);
                swapChar(&character[j], &character[j + 1]);
                swap(&start[j], &start[j + 1]);
                swap(&end[j], &end[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void sortingEnd(char character[], int start[], int end[], int intervaldiff[], int size)
{
    int flag;
    for (int i = 0; i < size - 1; i++)
    {
        flag = 0;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (end[j] > end[j + 1])
            {
                swap(&intervaldiff[j], &intervaldiff[j + 1]);
                swapChar(&character[j], &character[j + 1]);
                swap(&start[j], &start[j + 1]);
                swap(&end[j], &end[j + 1]);
                flag = 1;
            }
        }
        if (flag == 0)
        {
            break;
        }
    }
}

void greedy(char character[], int start[], int end[], int intervaldiff[], int n, int smallLength)
{
    int i = 0;
    printf("Activities : %c ", character[i]);
    for (int m = 1; m < n; m++)
    {
        if (start[m] >= end[i] && intervaldiff[m] != smallLength)
        {
            printf("%c ", character[m]);
            i = m;
        }
    }
    printf("\n");
}

int main()
{
    int n, maxWeight;
    printf("Enter the no. of elements : ");
    scanf("%d", &n);
    char character[n];
    int start[n], end[n], intervaldiff[n];
    printf("Enter the activities character, start & end of interval : \n");
    for (int i = 0; i < n; i++)
        scanf(" %c%d%d", &character[i], &start[i], &end[i]);

    for (int i = 0; i < n; i++)
        intervaldiff[i] = end[i] - start[i];

    sortingInterval(character, start, end, intervaldiff, n);
    // printf("After sorting according to difference between interval : \n");
    // for (int  i = 0; i < n; i++)
    //     printf("%c %d %d %d\n", character[i], start[i], end[i], intervaldiff[i]);

    int smallLength = 0;
    for (int i = 1; i < n; i++)
        if (intervaldiff[i] == intervaldiff[i - 1])
            smallLength += 1;
        else
            break;

    printf("The least length interval(s) : ");
    for (int i = 0; i <= smallLength; i++)
        printf("%c ", character[i]);
    printf("\n");
    // printf("smallLength : %d\n", smallLength);
    smallLength = intervaldiff[smallLength];
    // printf("smallLength : %d\n", smallLength);

    sortingEnd(character, start, end, intervaldiff, n);
    // printf("After sorting according to finish of interval: \n");
    // for (int  i = 0; i < n; i++)
    //     if (intervaldiff[i] != smallLength)
    //         printf("%c %d %d %d\n", character[i], start[i], end[i], intervaldiff[i]);

    greedy(character, start, end, intervaldiff, n, smallLength);

    return 0;
}
