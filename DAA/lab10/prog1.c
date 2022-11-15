// Write a C program to implement the Longest Common Subsequence. Sample Inputs & outputs The LCS of HUMAN and CHIMPANZEE is HMAN
#include<stdio.h>
#include<string.h>
int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct ret {
    int n;
    int L[100][100];
}a;

int lcs(char* X, char* Y, int m, int n)
{
    int L[m + 1][n + 1];
    int i, j;
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            if (i == 0 || j == 0)                                 //if i or j is 0 then L[i][j] is 0
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])                        //if the last character of X and Y are same then L[i][j] is L[i-1][j-1]+1
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);          //if the last character of X and Y are not same then L[i][j] is max(L[i-1][j],L[i][j-1])
        }
    }
    // save data in structure
    a.n = L[m][n];
    for (i = 0; i <= m; i++)
    {
        for (j = 0; j <= n; j++)
        {
            a.L[i][j] = L[i][j];
        }
    }
    return a.n;
}

int backtrack(char* X, char* Y, int m, int n)
{
    if (m == 0 || n == 0)
        return 0;
    if (X[m - 1] == Y[n - 1])
    {
        backtrack(X, Y, m - 1, n - 1);
        printf("%c", X[m - 1]);
    }
    else if (a.L[m - 1][n] > a.L[m][n - 1])
        backtrack(X, Y, m - 1, n);
    else
        backtrack(X, Y, m, n - 1);
}

int main()
{
    char X[] = "HUMAN";
    char Y[] = "CHIMPANZEE";
    int m = strlen(X);
    int n = strlen(Y);
    //printing LCS
    printf("The LCS of %s and %s is %d", X, Y, lcs(X, Y, m, n));
    printf("\nThe possible sequence is ");
    backtrack(X, Y, m, n);
    return 0;
}