// Let A be a list of n (not necessarily distinct) integers. Write a program by using User Defined Function(UDF)s to test whether any item occurs more than n/2 times in A. 
#include <stdio.h>
#include <stdlib.h>
typedef unsigned long long ll;

struct map {
    int key;
    int value;
};

struct map* algo1(int* arr, int n) {

}

int main()
{
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        printf("Enter the element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }



    return 0;
}