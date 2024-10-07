#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int adj[MAX][MAX], visited[MAX], stack[MAX], top = -1;
int vertices;

void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adj[v][i] == 1 && !visited[i]) {
            dfs(i);
        }
    }
    stack[++top] = v;
}

void topologicalSort() {
    for (int i = 0; i < vertices; i++) {
        if (!visited[i]) {
            dfs(i);
        }
    }
    while (top != -1) {
        printf("%d ", stack[top--]);
    }
}

int main() {
    int edges, u, v;
    scanf("%d %d", &vertices, &edges);
    for (int i = 0; i < edges; i++) {
        scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    topologicalSort();
    return 0;
}
