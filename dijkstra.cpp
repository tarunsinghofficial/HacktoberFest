#include <cassert>
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <utility>
#include <vector>

constexpr int64_t INF = std::numeric_limits<int64_t>::max();

namespace graph {
 v any node or vertex of graph

void addEdge(std::vector<std::vector<std::pair<int, int>>> *adj, int u, int v,
             int w) {
    (*adj)[u - 1].push_back(std::make_pair(v - 1, w));
    // (*adj)[v - 1].push_back(std::make_pair(u - 1, w));
}

int dijkstra(std::vector<std::vector<std::pair<int, int>>> *adj, int s, int t) {
    // n denotes the number of vertices in graph
    int n = adj->size();

    /// setting all the distances initially to INF
    std::vector<int64_t> dist(n, INF);
    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                        std::greater<std::pair<int, int>>>
        pq;

    /// pushing the source vertex 's' with 0 distance in min heap
    pq.push(std::make_pair(0, s));

    /// marking the distance of source as 0
    dist[s] = 0;

    while (!pq.empty()) {
        int currentNode = pq.top().second;

        int currentDist = pq.top().first;

        pq.pop();

        for (std::pair<int, int> edge : (*adj)[currentNode]) {
            /// minimizing distances
            if (currentDist + edge.second < dist[edge.first]) {
                dist[edge.first] = currentDist + edge.second;
                pq.push(std::make_pair(dist[edge.first], edge.first));
            }
        }
    }
    if (dist[t] != INF) {
        return dist[t];
    }
    return -1;
}
}  // namespace graph

/** Function to test the Algorithm */
void tests() {
    std::cout << "Initiatinig Predefined Tests..." << std::endl;
    std::cout << "Initiating Test 1..." << std::endl;
    std::vector<std::vector<std::pair<int, int>>> adj1(
        4, std::vector<std::pair<int, int>>());
    graph::addEdge(&adj1, 1, 2, 1);
    graph::addEdge(&adj1, 4, 1, 2);
    graph::addEdge(&adj1, 2, 3, 2);
    graph::addEdge(&adj1, 1, 3, 5);

    int s = 1, t = 3;
    assert(graph::dijkstra(&adj1, s - 1, t - 1) == 3);
    std::cout << "Test 1 Passed..." << std::endl;

    s = 4, t = 3;
    std::cout << "Initiating Test 2..." << std::endl;
    assert(graph::dijkstra(&adj1, s - 1, t - 1) == 5);
    std::cout << "Test 2 Passed..." << std::endl;

    std::vector<std::vector<std::pair<int, int>>> adj2(
        5, std::vector<std::pair<int, int>>());
    graph::addEdge(&adj2, 1, 2, 4);
    graph::addEdge(&adj2, 1, 3, 2);
    graph::addEdge(&adj2, 2, 3, 2);
    graph::addEdge(&adj2, 3, 2, 1);
    graph::addEdge(&adj2, 2, 4, 2);
    graph::addEdge(&adj2, 3, 5, 4);
    graph::addEdge(&adj2, 5, 4, 1);
    graph::addEdge(&adj2, 2, 5, 3);
    graph::addEdge(&adj2, 3, 4, 4);

    s = 1, t = 5;
    std::cout << "Initiating Test 3..." << std::endl;
    assert(graph::dijkstra(&adj2, s - 1, t - 1) == 6);
    std::cout << "Test 3 Passed..." << std::endl;
    std::cout << "All Test Passed..." << std::endl << std::endl;
}

/** Main function */
int main() {
    // running predefined tests
    tests();

    int vertices = int(), edges = int();
    std::cout << "Enter the number of vertices : ";
    std::cin >> vertices;
    std::cout << "Enter the number of edges : ";
    std::cin >> edges;

    std::vector<std::vector<std::pair<int, int>>> adj(
        vertices, std::vector<std::pair<int, int>>());

    int u = int(), v = int(), w = int();
    while (edges--) {
        std::cin >> u >> v >> w;
        graph::addEdge(&adj, u, v, w);
    }

    int s = int(), t = int();
    std::cin >> s >> t;
    int dist = graph::dijkstra(&adj, s - 1, t - 1);
    if (dist == -1) {
        std::cout << "Target not reachable from source" << std::endl;
    } else {
        std::cout << "Shortest Path Distance : " << dist << std::endl;
    }
    return 0;
}
