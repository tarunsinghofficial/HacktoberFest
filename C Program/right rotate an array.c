#include <stdio.h>
#define SIZE 10 

void printArray(int arr[]);
void rotateByOne(int arr[]);


int main()
{
    int i, N;
    int arr[SIZE];

    printf("Enter 10 elements array: ");
    for(i=0; i<SIZE; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter number of times to right rotate: ");
    scanf("%d", &N);

   
    N = N % SIZE;

    
    printf("Array before rotationn");
    printArray(arr);

   
    for(i=1; i<=N; i++)
    {
        rotateByOne(arr);
    }

    
    printf("\n\nArray after rotation\n");
    printArray(arr);

    return 0;
}


void rotateByOne(int arr[])
{
    int i, last;

    
    last = arr[SIZE - 1];

    for(i=SIZE-1; i>0; i--)
    {
        
        arr[i] = arr[i - 1];
    }

    
    arr[0] = last;
}



void printArray(int arr[])
{
    int i;

    for(i=0; i<SIZE; i++)
    {
        printf("%d ", arr[i]);
    }
}
