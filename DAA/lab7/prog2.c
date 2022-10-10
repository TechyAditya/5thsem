// Similar to prog1.c, write a menu driven program to sort an array of n integers in descending order by heap sort algorithm, use min heap.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned long long ll;
ll steps;

// heapify
void heapify(int* arr, int n, int i)
{
    int smallest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    steps += 6; // for 3 initializations and 3 comparisons

    if (l < n && arr[l] < arr[smallest]) {
        smallest = l;
        steps++;
    }

    if (r < n && arr[r] < arr[smallest]) {
        smallest = r;
        steps++;
    }

    // If smallest is not root
    if (smallest != i) {
        int temp = arr[i];
        arr[i] = arr[smallest];
        arr[smallest] = temp;

        steps += 3;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, smallest);
    }
}

// heap sort
void heapSort(int* arr, int n)
{
    steps = 0;
    for (int i = n / 2 - 1; i >= 0; i--) 
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        steps += 3; 

        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;

        heapify(arr, i, 0);
    }
}

void classic()
{
    int n;
    printf("Enter n:");
    scanf("%d", &n);
    int* arr = (int*)malloc(n * sizeof(int));
    printf("Enter elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    heapSort(arr, n);
    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\nSteps: %llu\n", steps);
}

void printTable() {
    printf("Sl no.\tN\tSteps\n");
    int* arr;
    int i;
    int n;
    for (i = 1; i <= 10; i++) {
        n = i * 1000;
        arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            arr[j] = rand() % 1000;
        heapSort(arr, n);
        printf("%d\t%d\t%d\n", i, n, steps);
    }
}
int main() {
    int choice;
    srand(time(0));
    printf("1. Sort N elements\n2. Table\nEnter choice:");
    scanf("%d", &choice);
    switch (choice) {
    case 1:
        classic();
        break;
    case 2:
        printTable();
        break;
    default:
        printf("Invalid choice");
    }
    return 0;
}