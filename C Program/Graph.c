#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "graph.h"
int getn(graph *g){
	return g->n;
}
void ginit(graph *g, int n) {
	// malloc the 2-d array of size n x n at g->a
	int i, j;
	g->a = (int **)malloc(sizeof(int *) * n);
	for(i = 0; i < n; i++)
		g->a[i] = (int *)malloc(sizeof(int) * n);
	for(i = 0; i < n; i++)
		for(j = 0; j < n; j++)
			g->a[i][j] = 0; // edge is absent
	g->n = n;
}
// assume that g is not initialized
void buildGraphFromGraphFile(graph *g, char *filename) {
	FILE *fp;
	int x;
	int i, j;
	
	fp = fopen(filename, "r");
	if(fp == NULL)
		return;
	fscanf(fp, "%d", &x);	
	ginit(g, x);
	for(i = 0; i < x; i++)
		for(j = 0; j < x; j++) 
			fscanf(fp, "%d", &(g->a[i][j]));
}
void printGraph(graph *g) {
	int i, j;
	for(i = 0; i < g->n; i++) {
		for(j = 0; j < g->n; j++)
			printf("%d ", g->a[i][j]);
		printf("\n");
	}
}
#define LINESIZE 128
void buildGraphFromMapFile(graph *g, char *mapfile) {
	FILE *fp;
	char line[LINESIZE], *t1, *t2, *t3;
	char **citynames; // storing the city names
	int n = 0; // no. of cities = no. of vertices
	int size = 128;
	int i; // just a counter
	int v1, v2; // vertex no. for city1, city2
	fp = fopen(mapfile, "r");
	if(fp == NULL)
		return;
	
	citynames = (char **)malloc(sizeof(char *) * size);
	while(fgets(line, LINESIZE, fp)) {
		t1 = strtok(line, ","); // cityname1
		t2 = strtok(NULL, ","); // cityname2
		t3 = strtok(NULL, ","); // distance 
		for(i = 0; i < n; i++)
			if(strcmp(citynames[i], t1) == 0)
				break;
		if(i == n) { // not found {
			// append i.e. insert at citynames[n]	
			citynames[n] = (char *)malloc(strlen(t1) + 1);
			strcpy(citynames[n], t1);
			n++;
		}
		if(n == size) {
			size = size  << 1;
			citynames = (char **)realloc(citynames, size * sizeof(char *));	
		}
		for(i = 0; i < n; i++)
			if(strcmp(citynames[i], t2) == 0)
				break;
		if(i == n) { // not found {
			// append i.e. insert at citynames[n]	
			citynames[n] = (char *)malloc(strlen(t2) + 1);
			strcpy(citynames[n], t2);
			n++;
		}
		if(n == size) {
			size = size  << 1;
			citynames = (char **)realloc(citynames, size * sizeof(char *));	
		}
	}
	printf("%d\n", n);
	// n is the no. of vertices
	ginit(g, n);
	fseek(fp, SEEK_SET, 0);
	while(fgets(line, LINESIZE, fp))	 {
		t1 = strtok(line, ","); // cityname1
		t2 = strtok(NULL, ","); // cityname2
		t3 = strtok(NULL, ","); // distance 
		// search t1 in citynames and get v1 no. 
		for(i = 0; i < n; i++)
			if(strcmp(citynames[i], t1) == 0) 
				v1 = i;
		for(i = 0; i < n; i++)
			if(strcmp(citynames[i], t2) == 0)
				v2 = i;
		g->a[v1][v2] = atoi(t3);	
	}
}
void dft_r(graph *g, int x, int *visited) {
	int j;
	printf("%d ", x);
	visited[x] = 1;
	for(j = 0; j < g->n; j++) {
		if(g->a[x][j] && !visited[j])
			dft_r(g, j, visited);
	}
}
void dft(graph *g, int x) {
	int *visited = malloc(sizeof(int) * g->n);
	int i;
	for(i = 0; i < g->n; i++)
		visited[i] = 0;
	dft_r(g, x, visited);
	printf("\n");
	free(visited);
}
int findmin(graph *g, int *visited, int *distance) {
	int i, currmin = INT_MAX, minpos = -1;
	for(i = 0; i < g->n; i++) {
		if(distance[i] < currmin && !visited[i]) {
			currmin = distance[i];
			minpos = i;
		}
	}
	return minpos;
}
int *ssadsp(graph *g, int x) { // x is the source vertex
	int i, j, k, max = 0, u;
	int *distance = (int *)malloc(sizeof(int) * g->n);
	int *visited = (int *)malloc(sizeof(int) * g->n);
	for(i = 0; i < g->n; i++) 
		visited[i] = 0;
	/* find the infinity */
	for(i = 0; i < g->n; i++)
		for(j = 0; j < g->n; j++)
			max = max + g->a[i][j];
	/* calculate initial distance from x */
	for(i = 0; i < g->n; i++) {
		if(g->a[x][i])
			distance[i] = g->a[x][i];
		else
			distance[i] = max + 1;
	}
	for(i = 0; i < g->n - 1; i++) {
		u = findmin(g, visited, distance);
		visited[u] = 1;
		for(j = 0; j < g->n; j++) {
			if(g->a[u][j])
				if(!visited[j] && (distance[j] > (distance[u] + g->a[u][j])))
					distance[j] = distance[u] + g->a[u][j];
		}
	}
	free(visited);
	return distance;
}
edge *prims(graph *g, int x) {
	edge *edges = (edge *)malloc(sizeof(edge) * (g->n  -1)), minedge;
	int *visited = (int *)malloc(sizeof(int) * g->n);
	int minweight = INT_MAX, i, j, k;
	for(i = 0; i < g->n; i++) 
		visited[i] = 0;
	visited[x] = 1;
	int e = 0;
	for(i = 0; i < g->n - 1; i++) {
		minweight = INT_MAX;
		for(j = 0; j < g->n; j++) 
			for(k = 0; k < g->n; k++)
				if(g->a[j][k] && visited[j] && !visited[k]) {
					if(g->a[j][k] < minweight) {
						minweight = g->a[j][k];
						minedge.s = j;
						minedge.d = k;
						minedge.weight = minweight;
					}	
				}
		/*select an edge s.t.
			one end of the edge is in visited vertices
			other end is not in visited vertices
			it's the minimum of such edges
		add this edge to list of edges */
		edges[e++] = minedge;
		visited[minedge.d] = 1;
	}
	free(visited);
	return edges;	
}
