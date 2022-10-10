// Write a menu (given as follows) driven program to sort an array of n integers in ascending order by heap sort algorithmand perform the operations on max heap. Determine the time required to sort the elements.Repeat the experiment for different values of n, the number of elements in the array to be sortedand plot a graph of the time taken versus n.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
typedef unsigned long long ll;
ll steps;
// heapify
void heapify(int* arr, int n, int i)
{
    int largest = i;
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    steps += 6; // for 3 initializations and 3 comparisons

    if (l < n && arr[l] > arr[largest]) {
        largest = l;
        steps++;
    }

    if (r < n && arr[r] > arr[largest]) {
        largest = r;
        steps++;
    }

    // If largest is not root
    if (largest != i) {
        int temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;

        steps += 3;

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
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
    printf("Enter elements:");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    heapSort(arr, n);
    printf("Sorted array:");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    printf("\nSteps:%llu\n", steps);
}

void printTable() {
    printf("Sl no.\tN\tRandom\tSorted\tReverse\n");
    int* arr;
    int i;
    int n;
    int r, asc, desc;
    for (i = 1; i <= 10; i++) {
        n = i * 1000;
        arr = (int*)malloc(n * sizeof(int));
        for (int j = 0; j < n; j++)
            arr[j] = rand() % 1000;
        heapSort(arr, n);
        r = steps;
        heapSort(arr, n);
        asc = steps;
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