//WAP to find the frequency of numbers in an array
#include<stdio.h>
int main()
{
    int n;
    printf("Size: ");
    scanf("%d", &n);
    int a[n];
    printf("Elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int ctr[n];
    ctr[0]=1;
    for (int i = 1; i < n; i++) {
        int flag = 0;
        for (int j = 0; j < i; j++) {
            if(a[i]==a[j]) {
                ctr[j]++;
                flag=1;
                break;
            }
        }
        if(!flag)
            ctr[i]=1;
        else 
            ctr[i]=0;
    }
    
    printf("Frequency of numbers: \n");
    for (int i = 0; i < n; i++) {
        if(ctr[i]) {
            printf("%d - %d times \n", a[i], ctr[i]);
        }
    }
    return 0;
}