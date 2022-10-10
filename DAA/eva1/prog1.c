#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// max and min element using divide and conquer approach
int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int max_element(int *arr, int l, int r) {
    if (l == r) {
        return arr[l];
    }
    if (l + 1 == r) {
        return max(arr[l], arr[r]);
    }
    int mid = (l + r) / 2;
    int left_max = max_element(arr, l, mid);
    int right_max = max_element(arr, mid + 1, r);
    return max(left_max, right_max);
}

int min_element(int *arr, int l, int r) {
    if (l == r) {
        return arr[l];
    }
    if (l + 1 == r) {
        return min(arr[l], arr[r]);
    }
    int mid = (l + r) / 2;
    int left_min = min_element(arr, l, mid);
    int right_min = min_element(arr, mid + 1, r);
    return min(left_min, right_min);
}

int main()
{
    time_t start, end;
    int n;
    srand(time(0));
    printf("N\tMax\tMin\tMax-Time\tMin-Time\n");
    for (n = 5000; n <= 50000; n += 5000) {
        int *arr = (int *)malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i] = rand() % 100000;
        }
        
        start = clock();
        int max = max_element(arr, 0, n - 1);
        end = clock();
        double max_time = (double)(end - start) / CLOCKS_PER_SEC;

        start = clock();
        int min = min_element(arr, 0, n - 1);
        end = clock();
        double min_time = (double)(end - start) / CLOCKS_PER_SEC;

        printf("%d\t%d\t%d\t%f\t%f\n", n, max, min, max_time, min_time);
    }

    return 0;
}