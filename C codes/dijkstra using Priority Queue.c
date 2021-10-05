#include<stdio.h>
#define SIZE 5
#define INFINITY 99999

//********************DECLARING GLOBAL ARRAYS AND VARIABLES*********************************
//THESE INCLUDE PRIORITY QUEUE, MIN COST ARRAY, VISITED NODES AND SIZE OF QUEUE ***********

int prQueue[SIZE], minCost[SIZE], predecessor[SIZE], visited[SIZE];
int queueSize = 0;

//***************************SWAP FUNCTION****************************************************

void swap(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

//*************************FINDING LOCATIONS OF PARENT AND NODES*****************************

int parent(int i) 
{ 
    return (i-1)/2; 
}

int leftChild(int i) 
{ 
    return (2*i + 1); 
}

int rightChild(int i) 
{ 
    return (2*i + 2); 
}

//*******************CHECKING GRAPH IS VALID OR NOT ****************************************

int checkDijkstra(int graph[SIZE][SIZE])
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {

            //WEIGHT SHOULD NOT BE NEGATIVE
            if(graph[i][j] < 0)
            {
                return 0;
            }
        }
    }
    return 1;
}

//************************INSERTING ELEMENT INTO THE QUEUE******************

void push(int k)
{
    queueSize++;
    int i = queueSize - 1;
    prQueue[i] = k;
    while (i != 0 && minCost[prQueue[parent(i)]] > minCost[prQueue[i]])
    {
       swap(&prQueue[i], &prQueue[parent(i)]);
       i = parent(i);
    }
}
 
 //************************USING MIN HEAP HEAPIFY METHOD****************************
     
void heapify(int i)
{
    int l = leftChild(i);
    int r = rightChild(i);
    int smallest = i;
    if (l < queueSize && minCost[prQueue[l]] < minCost[prQueue[i]])
    {
        smallest = l;
    }
    if (r < queueSize && minCost[prQueue[r]] < minCost[prQueue[smallest]])
    {
        smallest = r;
    }
    if (smallest != i)
    {
        swap(&prQueue[i], &prQueue[smallest]);
        heapify(smallest);
    }
}

 //*******************DELETING ELEMENT FROM THE QUEUE*********************

int pop()
{
    if (queueSize <= 0)
    {
        return INFINITY;
    }
    if (queueSize == 1)
    {
        queueSize--;
        return prQueue[0];
    }
    int root = prQueue[0];
    prQueue[0] = prQueue[queueSize-1];
    queueSize--;
    heapify(0);
    return root;
}

//*************************ANSWERS*************************

void result(int source)
{
    int shortestPath[SIZE];
    int  j = 0;
    for(int i = 0 ; i < SIZE; i++)
    {
        printf("\nMinimum Cost from Source:  %d to Destination:   %d     =      %d\n", source, i, minCost[i]);
        int u = i;
        j = 0;
        while(u != source)
        {
            shortestPath[j] = u;
            j++;
            u = predecessor[u];
        }
        printf("The Shortest Path is:   ");
        printf("%d", source);
        for(int k = j - 1; k >= 0; k--)
        {
            printf(" -> %d", shortestPath[k]);
        }
        printf("\n");
    }
}

//************************************************DIJKSTRA ALGORITHM********************************

void dijkstraAlgo(int graph[SIZE][SIZE], int source)
{
    for(int i = 0; i < SIZE; i++)
    {
        minCost[i] = INFINITY;
        visited[i] = 0;
    }
    minCost[source] = 0;
    predecessor[source] = source;
    push(source);
    while(queueSize != 0)
    {
        int u = pop();
        visited[u] = 1;

        for(int i = 0; i < SIZE; i++)
        {
            if(graph[u][i] != 0 && visited[i] != 1)
            {
                if((graph[u][i] + minCost[u]) < minCost[i])
                {
                    minCost[i] = graph[u][i] + minCost[u];
                    predecessor[i] = u;
                    push(i);
                }
            }
        }
    }
    result(source);
}

//*************************MAIN FUNCTION*********************************************
int main()
{
  int graph[SIZE][SIZE],i,j,n;
    printf("Enter the number of vertices in the graph : ");
    scanf("%d",&n);
    printf("\nEnter the Adjacency Matrix of the graph [ Put 0 if the weight is unknown]:  \n");
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            scanf("%d",&graph[i][j]);
        }
    }
    if(checkDijkstra(graph))
    {
        printf("\nAPPLYING DIJKSTRA WITH SOURCE = 0\n");
        dijkstraAlgo(graph, 0);
    }
    else
    {
        printf("\nNegative Weight found. Dijkstra Algorithm cannot be applied!!!!!\n");
    }
    return 0;
}