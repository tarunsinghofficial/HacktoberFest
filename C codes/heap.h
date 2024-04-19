//THIS IS THE HEADER FILE OF THE HEAP

#include <limits.h>
 
typedef struct node
{
    int value;
    int weight;
} node;

int maxSize = 999999;
node h[999999];
int size = 0;

//FUNCTIONS LIST

int parentNode(int );
int comparisonFunction(node , node);
void shiftUp(int );
void enqueue(int, int);
void shiftDown(int);
node getMin();
int extractMin();
void decreaseKey(int , int , int );
void Remove(int );

//FINDING POSITION OF THE REQUIRED NODE

int parentNode(int i)
{
    return (i - 1) / 2;
}
int leftchild(int i)
{
    return 2*i + 1;
}
int rightchild(int i)
{
    return 2*i + 2;
}

//COMPARE FUNCTION 

int comparisonFunction(node x, node y)
{
    if (x.value < y.value)
    {
        return 1;
    }
    if (x.value == y.value)
    {
        if (x.weight < y.weight)
            return 1;
    }
    return 0;
}

//SHIFT UP FUNCTION

void shiftUp(int index)
{
    while (index != 0 && comparisonFunction(h[index], h[parentNode(index)]))
    {
        int x = h[index].value;
        int y = h[index].weight;
        h[index].value = h[parentNode(index)].value;
        h[index].weight = h[parentNode(index)].weight;
        h[parentNode(index)].value = x;
        h[parentNode(index)].weight = y;
        index = parentNode(index);
    }
}

//shiftDown FUNCTION

void shiftDown(int index)
{
    int min = index;
    int left = leftchild(index);
    int right = rightchild(index);
    if (left < size && comparisonFunction(h[left], h[min]))
    {
        min = left;
    }
    if (right < size && comparisonFunction(h[right], h[min]))
    {
        min = right;
    }
    if (index != min)
    {
        int x = h[index].value;
        int y = h[index].weight;
        h[index].value = h[min].value;
        h[index].weight = h[min].weight;
        h[min].value = x;
        h[min].weight = y;
        shiftDown(min);
    }
}
 
//ENQUEUE FUNCTION

void enqueue(int x, int y)
{
    if (size == maxSize)
    {
        printf("SIZE FULL!!!\n");
        return;
    }
    else
    {
        size++;
        h[size - 1].value = x;
        h[size - 1].weight = y;
        shiftUp(size - 1);
    }
}

//GET MIN FUNCTION

node getMin()
{
    node x;
    x.value = h[0].value;
    x.weight = h[0].weight;
    return x;
}

//EXTRACT MINIMUM FUNCTION

int extractMin()
{
    if (size <= 0)
    {
        return INT_MAX;
    }
    if (size == 1)
    {
        size--;
        return h[0].value;
    }
    int result = h[0].value;
    h[0].value = h[size - 1].value;
    h[0].weight = h[size - 1].weight;
    size--;
    shiftDown(0);
    return result;
}

//REMOVE FUNCTION

void Remove(int i)
{
    h[i].value = -INT_MAX;
    h[i].weight = INT_MAX;
    shiftUp(i);
    extractMin();
}

//DECREASE KEY FUNCTION

void decreaseKey(int i, int neg, int y)
{
    h[i].value = neg;
    h[i].weight = y;
    shiftUp(i);
}