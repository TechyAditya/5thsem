#include <stdio.h>
#include <stdlib.h>

int DUPLICATE_SET_ASC(int a[], int p, int r, int* b) {
    // find duplicate elements in array
    int n = r - p + 1;
    int retsize = 0;
    for (int i = 0; i < n - 1; i++) {
        if (a[i] == a[i + 1]) {
            int flag = 1;
            for(int j = 0; j < retsize && flag; j++) {
                if (b[j] == a[i]) {
                    flag = 0;
                }
            }
            if(flag == 1)
                b[retsize++] = a[i];
        }
    }
    return retsize;
}

int main()
{
    // question  1a
    int a1[] = { 2,3,3,3,3,4,4,5,7,8,8 };

    int n1 = sizeof(a1) / sizeof(int);
    int* set1 = (int*)malloc(n1 * sizeof(int));
    int size1 = DUPLICATE_SET_ASC(a1, 0, n1 - 1, set1);

    for(int i = 0; i < size1; i++) {
        printf("%d ", set1[i]);
    }
    printf("\n");

    // question 1b
    int a2[] = { 9,9,8,7,7,3,2,2,1 };
    int n2 = sizeof(a2) / sizeof(int);
    int* set2 = (int*)malloc(n2 * sizeof(int));
    int size2 = DUPLICATE_SET_ASC(a2, 0, n2 - 1, set2);

    for (int i = 0; i < size2; i++) {
        printf("%d ", set2[i]);
    }
    printf("\n");

    return 0;
}