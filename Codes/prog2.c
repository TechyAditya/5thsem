// program to visit all nodes in a complete undirected graph
#include <stdio.h>
#include <stdlib.h>
int main()
{
    int n, i, j, k, l, m, a[100][100], b[100], c[100], d[100], e[100], f[100], g[100], h[100], p, q, r, s, t, u, v, w, x, y, z;
    printf("Enter the number of nodes: ");
    scanf("%d", &n);
    printf("Enter the adjacency matrix: ");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    for (i = 0; i < n; i++)
    {
        b[i] = 0;
        c[i] = 0;
        d[i] = 0;
        e[i] = 0;
        f[i] = 0;
        g[i] = 0;
        h[i] = 0;
    }
    printf("Enter the starting node: ");
    scanf("%d", &p);
    b[p] = 1;
    printf("The nodes visited are: ");
    printf("%d ", p);
    for (i = 0; i < n; i++)
    {
        if (a[p][i] == 1)
        {
            c[i] = 1;
        }
    }
    for (i = 0; i < n; i++)
    {
        if (c[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    d[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (d[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    e[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (e[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    f[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (f[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    g[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (g[i] == 1)
        {
            for (j = 0; j < n; j++)
            {
                if (a[i][j] == 1)
                {
                    h[j] = 1;
                }
            }
        }
    }
    for (i = 0; i < n; i++)
    {
        if (c[i] == 1)
        {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (d[i] == 1)
        {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (e[i] == 1)
        {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (f[i] == 1)
        {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (g[i] == 1)
        {
            printf("%d ", i);
        }
    }
    for (i = 0; i < n; i++)
    {
        if (h[i] == 1)
        {
            printf("%d ", i);
        }
    }
    

    return 0;
}