// Write a program to search an element x in an array of n integers using binary search algorithm that uses divide and conquer technique. Find out the best case, worst case and average case time complexities for different values of n and plot a graph of the time taken versus n. The n integers can be generated randomly and x can be chosen randomly, or any element of the array or middle or last element of the array depending on type of time complexity analysis.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
typedef unsigned long long ll;
ll steps;

// insertion sort
void insertionSort(int* arr, int n)
{
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// binary search using divide and conquer algorithm
int binarySearch(int* arr, int n, int x)
{
    int low = 0, high = n - 1, mid;
    steps = 1;
    while (low <= high)
    {
        steps++;
        mid = (low + high) / 2;
        steps++;
        if (arr[mid] == x)
        {
            steps++;
            return mid;
        }
        else if (arr[mid] < x)
        {
            steps += 2;
            low = mid + 1;
        }
        else
        {
            steps += 3;
            high = mid - 1;
        }
    }
    steps++;
    return -1;
}

void printTable() {
    printf("Sl no.\tN\tAverage\tBest\tWorst\n");
    int* arr;
    int i;
    ll n;
    for (i = 1, n = 2 << i; i <= 15; i++, n = 2 << i) {
        arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
        insertionSort(arr, n);

        int x = arr[rand() % n];

        int pos = binarySearch(arr, n, x);
        ll avg = steps;
        steps = 0;

        x = arr[(n - 1) / 2];
        pos = binarySearch(arr, n, x);
        ll best = steps;
        steps = 0;

        x = -1;
        pos = binarySearch(arr, n, x);
        ll worst = steps;
        steps = 0;

        printf("%d\t%llu\t%llu\t%llu\t%llu\n", i, n, avg, best, worst);
    }
}

int main()
{
    srand((unsigned)clock());
    printTable();

    return 0;
}