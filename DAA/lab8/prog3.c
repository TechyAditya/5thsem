// 6.3- menu driven program of huffman coding
// Huffman coding assigns variable length codewords to fixed length input characters
// based on their frequencies/probabilities of occurrence. Given an array of characters along
// with their frequency of occurrences. Write a menu driven programming to perform the
// following functions.
// 0. Quit
// 1. Input n unique characters with their frequencies into an array
// 2. Display the Array
// 3. Generate Huffman Tree and Traverse the tree with pre-order.
// 4. Generate Huffman Codes for n charachers and display the
// same.
// 5. Compare Huffman code with Fixed-Length Code

#include <stdio.h>
#include <stdlib.h>
#define MAX_TREE_HT 50
struct MinHNode
{
    char item;
    unsigned freq;
    struct MinHNode* left, * right;
};
struct MinHeap
{
    unsigned size;
    unsigned capacity;
    struct MinHNode** array;
};
struct MinHNode* newNode(char item, unsigned freq)
{
    struct MinHNode* temp = (struct MinHNode*)malloc(sizeof(struct MinHNode));
    temp->left = temp->right = NULL;
    temp->item = item;
    temp->freq = freq;
    return temp;
}
struct MinHeap* createMinH(unsigned capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->array = (struct MinHNode**)malloc(minHeap->capacity * sizeof(struct MinHNode*));
    return minHeap;
}
void swapMinHNode(struct MinHNode** a, struct MinHNode** b)
{
    struct MinHNode* t = *a;
    *a = *b;
    *b = t;
}
void minHeapify(struct MinHeap* minHeap, int idx)
{
    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;
    if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
        smallest = left;
    if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
        smallest = right;
    if (smallest != idx)
    {
        swapMinHNode(&minHeap->array[smallest], &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}
int checkSizeOne(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
struct MinHNode* extractMin(struct MinHeap* minHeap)
{
    struct MinHNode* temp = minHeap->array[0];
    minHeap->array[0] = minHeap->array[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}
void insertMinHeap(struct MinHeap* minHeap, struct MinHNode* minHeapNode)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq)
    {
        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->array[i] = minHeapNode;
}
void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}
int isLeaf(struct MinHNode* root)
{
    return !(root->left) && !(root->right);
}
struct MinHeap* createAndBuildMinHeap(char item[], int freq[], int size)
{
    struct MinHeap* minHeap = createMinH(size);
    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(item[i], freq[i]);
    minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}
struct MinHNode* buildHuffmanTree(char item[], int freq[], int size)
{
    struct MinHNode* left, * right, * top;
    struct MinHeap* minHeap = createAndBuildMinHeap(item, freq, size);
    while (!checkSizeOne(minHeap))
    {
        left = extractMin(minHeap);
        right = extractMin(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        insertMinHeap(minHeap, top);
    }
    return extractMin(minHeap);
}
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d", arr[i]);

    printf("\n");
}
void printHCodes(struct MinHNode* root, int arr[], int top)
{
    if (root->left)
    {
        arr[top] = 0;
        printHCodes(root->left, arr, top + 1);
    }
    if (root->right)
    {
        arr[top] = 1;
        printHCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root))
    {
        printf("  %c   | ", root->item);
        printArray(arr, top);
    }
}
void HuffmanCodes(char item[], int freq[], int size)
{
    struct MinHNode* root = buildHuffmanTree(item, freq, size);
    int arr[MAX_TREE_HT], top = 0;
    printHCodes(root, arr, top);
}
int main()
{
    int n;
    int choice;
    do
    {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 0:
        {
            printf("Quit");
            return 0;
            break;
        }
        case 1:
        {
            printf("Enter Array Size: ");
            scanf("%d", &n);
            char arr[n];
            int freq[n];
            printf("Enter Unique Characters:\n");
            for (int i = 0; i < n; i++) 
            {
                printf("Enter Character - %d: \n", i + 1);
                scanf("\n%c", &arr[i]);
            }
            printf("Enter their Frequencies:\n");
            for (int i = 0; i < n; i++)
            {
                printf("Enter Frequency of Character - %d: ", i + 1);
                scanf("%d", &freq[i]);
            }
            printf("Huffmaan Code for the Characters:\n");
            HuffmanCodes(arr, freq, n);
            break;
        }
        }
    } while (1);
    return 0;
}