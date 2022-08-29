// Write a program to search an element x in an array of n integers using binary search algorithm that uses divide and conquer technique. Find out the best case, worst case and average case time complexities for different values of n and plot a graph of the time taken versus n. The n integers can be generated randomly and x can be chosen randomly, or any element of the array or middle or last element of the array depending on type of time complexity analysis.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
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
            steps++;
            low = mid + 1;
        }
        else
        {
            steps++;
            high = mid - 1;
        }
    }
    steps++;
    return -1;
}

// reverse array
void reverseArray(int* arr, int n)
{
    int i, j;
    for (i = 0, j = n - 1; i < j; i++, j--)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int main()
{
    int n;
    srand((unsigned)clock());
    printf("Enter n: ");
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100;
    }

    insertionSort(arr, n);

    int x = arr[rand() % n];

    int pos = binarySearch(arr, n, x);
    ll avg = steps;
    steps = 0;

    x = arr[(n-1)/2];
    pos = binarySearch(arr, n, x);
    ll best = steps;
    steps = 0;
    
    x = -1;
    pos = binarySearch(arr, n, x);
    ll worst = steps;
    steps = 0;

    printf("\nBest Case: %llu steps\nWorst Case: %llu steps\nAverage Case: %llu steps\n", best, worst, avg);

    return 0;
}