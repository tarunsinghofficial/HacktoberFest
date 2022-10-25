/* Spanning tree - A spanning tree is the subgraph of an undirected connected graph.
Minimum Spanning tree - Minimum spanning tree can be defined as the spanning tree in which the sum of the weights of the edge is minimum. The weight of the spanning tree is the sum of the weights given to the edges of the spanning tree.



Prim's Algorithm is a greedy algorithm that is used to find the minimum spanning tree from a graph. Prim's algorithm finds the subset of edges that includes every vertex of the graph such that the sum of the weights of the edges can be minimized.

Prim's algorithm starts with the single node and explores all the adjacent nodes with all the connecting edges at every step. The edges with the minimal weights causing no cycles in the graph got selected.*/

// Here is the code Implementation

#include <iostream>
#define I INT_MAX
using namespace std; 
int cost[][8]= 
 {{I,I,I,I,I,I,I,I}, 
 {I,I,25,I,I,I,5,I}, 
 {I,25,I,12,I,I,I,10}, 
 {I,I,12,I,8,I,I,I}, 
 {I,I,I,8,I,16,I,14}, 
 {I,I,I,I,16,I,20,18}, 
 {I,5,I,I,I,20,I,I}, 
 {I,I,10,I,14,18,I,I}}; 
int near[8]={I,I,I,I,I,I,I,I}; 
int t[2][6]; 
int main() 
{ 
 int i,j,k,u,v,n=7,min=I; 
 
 for(i=1;i<=n;i++) 
 { 
 for(j=i;j<=n;j++) 
 { 
 if(cost[i][j]<min) 
 { 
 min=cost[i][j]; 
 u=i; 
 v=j; 
 } 
 } 
 } 
 t[0][0]=u;t[1][0]=v; 
 near[u]=near[v]=0; 
 
 for(i=1;i<=n;i++) 
 { 
 if(near[i]!=0) 
 { 
 if(cost[i][u]<cost[i][v]) 
 near[i]=u; 
 else
 near[i]=v; 
 } 
 } 
 
 for(i=1;i<n-1;i++) 
 { 
 min=I; 
 for(j=1;j<=n;j++) 
 { 
 if(near[j]!=0 && cost[j][near[j]]<min) 
 { 
 k=j; 
 min=cost[j][near[j]]; 
 } 
 } 
 t[0][i]=k; 
 t[1][i]=near[k]; 
 near[k]=0; 
 
 for(j=1;j<=n;j++) 
 { 
 if(near[j]!=0 && cost[j][k]<cost[j][near[j]]) 
 near[j]=k; 
 } 
 
 } 
 
 for(i=0;i<n-1;i++) 
 { 
 cout<<"("<<t[0][i]<<","<<t[1][i]<<")"<<endl; 
 } 
 
}