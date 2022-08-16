// How to calculate time taken of any code segment? 
#include <stdio.h>
#include <time.h>
int main()
{
    time_t start, end;
    double time;
    
    start = clock();
    // code segment to be measured
    for(int i = 0; i < 10000000; i++);
    end = clock();
    time = (double)(end - start) / CLOCKS_PER_SEC;
    
    printf("Time taken: %f\n", time);
    return 0;
}