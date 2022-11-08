// Write a program to sort a list of n elements using the merge sort method and determine the time required to sort the elements. Repeat the experiment for different values of n and different nature of data (random data, sorted data, reversely sorted data) in the list.n is the user input and n integers can be generated randomly. Finally plot a graph of the time taken versus n.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned long long ll;
ll steps;
void swap(int* l, int* r) {
    int temp = *l;
    *l = *r;
    *r = temp;
}

// Merge function, accepts array, left, mid, right pointers of array
void merge(int* arr, int l, int mid, int r) {
    int size2 = r - mid;
    int arr2[size2];
    // separating 2nd array
    steps++;
    for (int i = 0; i < size2; i++) {
        steps++;
        arr2[i] = arr[mid + 1 + i];
    }
    // three pointered merging
    int ptr1 = mid;
    int ptr2 = r;
    int ptr3 = size2 - 1;
    steps++;
    while (ptr3 != -1) {
        steps++;
        if (ptr1 != -1 && arr[ptr1] > arr2[ptr3]) {
            steps += 2;
            arr[ptr2] = arr[ptr1];
            ptr1--; ptr2--;
        }
        else {
            steps += 3;
            arr[ptr2] = arr2[ptr3];
            ptr3--; ptr2--;
        }
    }
    steps++;
    while (ptr1 != -1) {
        steps += 2;
        arr[ptr2] = arr[ptr1];
        ptr1--; ptr2--;
    }
}

// Merge Sort, accepts array pointer, left pointer, right pointer
void mergeSort(int* arr, int l, int r) {
    steps++;
    if (l == r) return;
    steps++;
    if (l == r - 1 && arr[l] > arr[r]) {
        steps += 3;
        swap(&l, &r);
        return;
    }
    int mid = (l + r) / 2;
    mergeSort(arr, l, mid);
    mergeSort(arr, mid + 1, r);
    merge(arr, l, mid, r);
    steps += 4;
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

void printTable() {
    printf("Sl no.\tN\tRandom\t\tSorted\t\tUnsorted\n");
    int* arr;
    int i;
    ll n;
    for (i = 1, n = 5000; i <= 10; n += 5000, i++) {
        arr = (int*)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100;
        }
        steps = 0;
        mergeSort(arr, 0, n - 1);
        ll avg = steps;

        steps = 0;
        mergeSort(arr, 0, n - 1);
        ll best = steps;

        steps = 0;
        reverseArray(arr, n);
        mergeSort(arr, 0, n - 1);
        ll worst = steps;

        printf("%d\t%llu\t%llu\t%llu\t%llu\n", i, n, avg, best, worst);
    }
}

int main()
{
    srand((unsigned)clock());

    printTable();
    return 0;
}

