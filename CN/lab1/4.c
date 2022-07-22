// Store names, IDs, ph nos of 10 students in an array of structures. Display info upon request.
#include <stdio.h>
#include <stdlib.h> 
struct stud {
    char names[20];
    char id[10];
    char ph[15];
}s[10];
int main()
{
    for (int i = 0; i < 3; i++)
    {
        printf("\nEnter details for student %d: \n", i + 1);
        printf("Name: ");
        scanf("%s", s[i].names);
        printf("ID: ");
        scanf("%s", s[i].id);
        printf("Phone Number: ");
        scanf("%s", s[i].ph);

    }

    while (1) {
        printf("\nEnter student number (0 to exit): ");
        int inp;
        scanf("%d", &inp);
        if (inp == 0)
            return 0;
        printf("Name: %s\n", s[inp - 1].names);
        printf("ID: %s\n", s[inp - 1].id);
        printf("Phone Number: %s\n", s[inp].ph);
    }
}