#include <iostream>
#include <climits>
using namespace std;
struct Edge
{
    int src,dest,weight;
};
struct Graph
{
    int V , E;
    Edge *edge;
    Graph(int V,int E)
    {
        this->V=V;
        this->E=E;
        edge = new Edge[E];

    }
};

void printArr(int dist[], int n)
{
    cout << "Vertex Distance from Source\n";
    for (int i = 0; i < n; ++i)
        cout << i << "\t\t" << dist[i] << "\n";
}
void BellmanFord(Graph *graph, int src)
{
    int V = graph->V;
    int E = graph->E;
    int dist[V];
    for (int i = 0; i < V; i++)
    {
        dist[i] = INT_MAX;
    }
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++)
    {
        for (int j = 0; j < E; j++)
        {
            int u = graph->edge[j].src;
            int v = graph->edge[j].dest;
            int weight = graph->edge[j].weight;
            if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
                dist[v] = dist[u] + weight;
        }
    }
    for (int i = 0; i < E; i++)
    {
        int u = graph->edge[i].src;
        int v = graph->edge[i].dest;
        int weight = graph->edge[i].weight;
        if (dist[u] != INT_MAX && dist[u] + weight < dist[v])
        {
            cout << "Graph contains negative weight cycle";
            return;
        }
    }
    printArr(dist, V);
}
int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;
    Graph *graph = new Graph(V, E);
    for (int i = 0; i < E; i++)
    {
        int src, dest, weight;
        cout << "Enter source, destination, and weight for edge " << i + 1 << ": ";
        cin >> src >> dest >> weight;
        graph->edge[i].src = src;
        graph->edge[i].dest = dest;
        graph->edge[i].weight = weight;
    }
    int source;
    cout << "Enter the source vertex: ";
    cin >> source;
    BellmanFord(graph, source);
    return 0;
}
