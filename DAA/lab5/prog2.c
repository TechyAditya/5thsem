// 2. Design a data structure to maintain a set S of n distinct integers that supports the following two operations:
// a) INSERT(x, S): insert integer x into S
// b) REMOVE(S): remove the smallest n/2 integers from S.
// c) DISPLAY(S): display the contents of S.
// d) Write a program by using UDFs that give the worse-case time complexity of the two operations INSERT(x, S) in O(1) time and REMOVE(S) in O(n) time.
#include <stdio.h>
#include <stdlib.h>

int *sets;
int n = 0;

// insert into sorted array
void insert(int x)
{
    int i = n - 1;
    while (i >= 0 && sets[i] > x)
    {
        sets[i + 1] = sets[i];
        i--;
    }
    if(!n || sets[i] != x) {
        sets = (int *)realloc(sets, (n + 1) * sizeof(int));
        sets[i + 1] = x;
        n++;
    }
    else {
        while(i < n - 1) {
            i++;
            sets[i] = sets[i + 1];
        }
    }
}

// remove first n/2 elements
void removeFirstHalf()
{
    int half = n % 2 == 0 ? n / 2 : n / 2 + 1;
    for (int i = 0; i < half; i++)
        sets[i] = sets[i + n / 2];
    n = half;
    sets = (int *)realloc(sets, n * sizeof(int));
}

int main()
{
    printf("Enter the number of elements to insert into set: ");
    int num;
    scanf("%d", &num);
    printf("Enter the elements of the set: ");
    for (int i = 0; i < num; i++)
    {
        int x;
        scanf("%d", &x);
        insert(x);
    }

    int choice;
    while (1) {
        printf("\n1. INSERT(x, S)");
        printf("\n2. REMOVE(S)");
        printf("\n3. DISPLAY(S)");
        printf("\n4. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            int x;
            scanf("%d", &x);
            insert(x);
            break;
        case 2:
            removeFirstHalf();
            break;
        case 3:
            for (int i = 0; i < n; i++)
                printf("%d ", sets[i]);
            printf("\n");
            break;
        case 4:
            return 0;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
