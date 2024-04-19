#include <stdio.h>
#include <stdlib.h>
#include "heap.h"
#define ll long long

typedef struct edgePair
{
    int weightArray;
    int weightArrayIndex;
} edgePair;
 
//GLOBAL VARIABLES/ARRAYS

int storage[9999];
int rank[9999];
edgePair edges[999999];
int nodesArray[9999][9999];

//FUNCTIONS LIST

int Find(int);
void Union(int , int );

//FIND FUNCTION

int Find(int x)
{
    if (storage[x] < 0)
        return x;
    return storage[x] = Find(storage[x]);
}

//UNION FUNCTION

void Union(int x, int y)
{
    printf("\n");
    if (rank[x] > rank[y])
    {
        int j = 0;
        for (int i = rank[x]; i < rank[y] + rank[x]; i++)
        {
            nodesArray[x][i] = nodesArray[y][j++];
        }
        for (int i = 0; i < rank[x] + rank[y]; i++)
        {
            printf("%d ", nodesArray[x][i]);
        }
        printf("\n");
        storage[x] += storage[y];
        rank[x] += rank[y];
        storage[y] = x;
    }
    else
    {
        int j = 0;
        for (int i = rank[y]; i < rank[y] + rank[x]; i++)
        {
            nodesArray[y][i] = nodesArray[x][j++];
        }
        for (int i = 0; i < rank[x] + rank[y]; i++)
        {
            printf("%d ", nodesArray[y][i]);
        }
        printf("\n");
        storage[y] += storage[x];
        rank[y] += rank[x];
        storage[x] = y;
    }
}

//DRIVER CODE

int main()
{
    int n, e;
    printf("Enter the number of nodes present in the graph.\n");
    scanf("%d", &n);
    printf("Enter the number of edges present in the graph.\n");
    scanf("%d",&e);
    for (int i = 1; i <= n; i++)
    {
        nodesArray[i][0] = i;
        rank[i] = 1;
        storage[i] = -1;
    }
    int u, v, weight;
    printf("Enter the edges and weights like [ source    destination    weight]\n");
    printf("Please take the starting vertex as 1.\n");
    for (int i = 0; i < e; i++)
    {
        scanf("%d%d%d", &u, &v, &weight);
        edges[i].weightArray = u;
        edges[i].weightArrayIndex = v;
        enqueue(weight, i);
    }
    long long minWt = 0;
    printf("******************************************************************************");
    printf("\nPrinting all the disjoint sets: \n");
    for (int i = 0; i < e; i++)
    {
        node c = getMin();
        extractMin();
        u = edges[c.weight].weightArray;
        v = edges[c.weight].weightArrayIndex;
        u = Find(u);
        v = Find(v);
        if (u != v)
        {

            Union(u, v);
            minWt+= c.value;
        }
    }

        printf("******************************************************************************");
        printf("\n");
    printf("The Minimum Weight Of the Graph using Kruskal Algorithm is : %lld\n", minWt);
 
    return 0;
}