#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define MAX_HEIGHT 100

typedef struct
{
    char ch;
    char code[20];
}Huffman_Codes;

Huffman_Codes codeStorage[100];
int value = 0;

struct Huffman_node 
{
    char data;
    int freq;
    struct Huffman_node *left, *right;
};

struct MinHeap 
{ 
    int size;
    int capacity; 
    struct Huffman_node** arr;
};

struct Huffman_node* newNode(char data, int freq)
{
    struct Huffman_node* temp = (struct Huffman_node*)malloc(sizeof(struct Huffman_node));
 
    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;
 
    return temp;
}

struct MinHeap* createMinHeap(int capacity)
{
    struct MinHeap* minHeap = (struct MinHeap*)malloc(sizeof(struct MinHeap));
    minHeap->size = 0;
    minHeap->capacity = capacity;
    minHeap->arr = (struct Huffman_node**)malloc(minHeap->capacity * sizeof(struct Huffman_node));
    return minHeap;
}

void swap(struct Huffman_node** x, struct Huffman_node** y)
{
    struct Huffman_node* temp = *x;
    *x = *y;
    *y = temp;
}

void minHeapify(struct MinHeap* minHeap, int index)
{
    int minimum = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if ((left < minHeap->size)  &&  (minHeap->arr[left]->freq < minHeap->arr[minimum]->freq) )
        minimum = left;
    if ((right < minHeap->size)  &&  (minHeap->arr[right]->freq < minHeap->arr[minimum]->freq) )
        minimum = right;
    if (minimum != index) 
    {
        swap(&minHeap->arr[minimum], &minHeap->arr[index]);
        minHeapify(minHeap, minimum);
    }
}

struct Huffman_node* minValue(struct MinHeap* minHeap)
{
    struct Huffman_node* temp = minHeap->arr[0];
    minHeap->arr[0] = minHeap->arr[minHeap->size - 1];
    --minHeap->size;
    minHeapify(minHeap, 0);
    return temp;
}

void buildMinHeap(struct MinHeap* minHeap)
{
    int n = minHeap->size - 1;
    int i;
 
    for (i = (n - 1) / 2; i >= 0; --i)
    {
        minHeapify(minHeap, i);
    }
}

void displayArray(int arr[], int n, char ch)
{
    codeStorage[value].ch = ch;
    int i, x = 0;
    for (i = 0; i < n; ++i)
    {
        printf("%d", arr[i]);
        codeStorage[value].code[i] = arr[i] + '0';
    }
    value++;
    printf("\n");
}

int isLeaf(struct Huffman_node* root)
{
    return !(root->left) && !(root->right);
}

struct MinHeap* minHeapMaking(char data[], int freq[], int size) 
{
    struct MinHeap* minHeap = createMinHeap(size);
    for (int i = 0; i < size; ++i)
    {
        minHeap->arr[i] = newNode(data[i], freq[i]);
    }
     minHeap->size = size;
    buildMinHeap(minHeap);
    return minHeap;
}

int checkSize(struct MinHeap* minHeap)
{
    return (minHeap->size == 1);
}
 
void displayCodes(struct Huffman_node* root, int arr[], int top)
{
    if (root->left) {
        arr[top] = 0;
        displayCodes(root->left, arr, top + 1);
    }
    if (root->right) {
        arr[top] = 1;
        displayCodes(root->right, arr, top + 1);
    }
    if (isLeaf(root)) {
        printf("%c  : ", root->data);
        displayArray(arr, top, root->data);
    }
}
void moveDown(struct MinHeap* minHeap, struct Huffman_node* node)
{
    ++minHeap->size;
    int i = minHeap->size - 1;
    while (i && node->freq < minHeap->arr[(i - 1) / 2]->freq) 
    {
        minHeap->arr[i] = minHeap->arr[(i - 1) / 2];
        i = (i - 1) / 2;
    }
    minHeap->arr[i] = node;
}

struct Huffman_node* HuffmanTreeMaking(char data[], int freq[], int size)
{
    struct Huffman_node *left, *right, *top;
    struct MinHeap* minHeap = minHeapMaking(data, freq, size);
    while (!checkSize(minHeap)) 
    {
        left = minValue(minHeap);
        right = minValue(minHeap);
        top = newNode('$', left->freq + right->freq);
        top->left = left;
        top->right = right;
        moveDown(minHeap, top);
    }
    return minValue(minHeap);
}

void displayTable(char *arr, int *freq, int size)
{
    printf("\nFrequency Table of the following String is:  \n");
    for(int i = 0; i < size; i++)
    {
        printf("Alphabet    %c  :  %d   times\n", arr[i], freq[i]);
    }
}

int freqCount(char* alpha, int* frequency, char* arr, int len)
{
    char ch;
    int count, flag = 0, m = 0;
    for(int i = 0; i < len; i++)
    {
        flag = 0;
        ch = alpha[i];
        count = 0;
        for(int k = 0; k < m; k++)
        {
            if(ch == arr[k])
            {
                flag = 1;
            }
        }
        if(!flag)
        {
            for(int j = i; j < len; j++)
            {
                if(ch == alpha[j])
                    count++;
            }
            arr[m] = ch;
            frequency[m] = count;
            m++;
        }
    }

    displayTable(arr, frequency, m);

    return m;
}

void stringCoding(char *arr, char *result, int length)
{
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < value; j++)
        {
            if(codeStorage[j].ch == arr[i])
            {
                strcat(result, codeStorage[j].code);
                break; 
            }
        }
    }
}

void generateHuffmanCodes(char data[], int freq[], int size)
{
    struct Huffman_node* root = HuffmanTreeMaking(data, freq, size);
    int arr[MAX_HEIGHT], top = 0;
    printf("\nHuffman Codes Table for the given String is:\n");
    displayCodes(root, arr, top);
}

int main()
{
    char arr[100];
    char alpha[100];
    char result[100] = " ";
    printf("\nEnter some string : ");
    gets(alpha);
    int length = strlen(alpha);
    int frequency[100]; 
    int size = freqCount(alpha, frequency, arr, length);
    generateHuffmanCodes(arr, frequency, size);
    stringCoding(alpha, result, length);
    printf("\nThe Huffman Code for the given string is:  %s\n", result);
    return 0;
}