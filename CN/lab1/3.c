// Accept a sentence and print avg number of letters in each word
#include <stdio.h>
#include <stdlib.h>
int main()
{
    printf("Enter sentence:\n");
    char sen[50];
    scanf("%[^\n]s", sen);
    int wd = 0, ctr = 1;
    for(int i = 0; sen[i] != '\0'; i++) {
        switch(sen[i]) {
            case ' ':
                ctr++;
                break;
            default: 
                wd++;
        }
    }
    printf("Average word size = %f\n", (float)wd/ctr);

    return 0;
}