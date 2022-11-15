// given a linked list, perform insertion sort
#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node* next;
};
int main()
{
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    struct node* head = NULL;
    struct node* temp = NULL;
    printf("Enter the data: ");
    for (int i = 0; i < n; i++)
    {
        struct node* new_node = (struct node*)malloc(sizeof(struct node));
        scanf("%d", &new_node->data);
        new_node->next = NULL;
        if (head == NULL)
        {
            head = new_node;
            temp = new_node;
        }
        else
        {
            temp->next = new_node;
            temp = new_node;
        }
    }
    // insertion sort
    struct node* curr = head->next;
    struct node* prev = head;
    while (curr != NULL)
    {
        struct node* temp = head;
        struct node* prev_temp = NULL;
        while (temp != curr)
        {
            if (temp->data > curr->data)
            {
                prev->next = curr->next;
                curr->next = temp;
                if (prev_temp == NULL)
                {
                    head = curr;
                }
                else
                {
                    prev_temp->next = curr;
                }
                break;
            }
            prev_temp = temp;
            temp = temp->next;
        }
        if (temp == curr)
        {
            prev = curr;
            curr = curr->next;
        }
    }
    // print the sorted list
    struct node* temp1 = head;
    while (temp1 != NULL)
    {
        printf("%d ", temp1->data);
        temp1 = temp1->next;
    }

    return 0;
}