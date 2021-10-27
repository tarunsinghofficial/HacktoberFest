#Generate by GitHub Copilot

#Dijkstra Algorithm
def dijkstra(graph, start, end):
    #initialize the cost of the path from the start node to the start node
    cost = {start: 0}
    #initialize the path from the start node to the start node
    path = {start: [start]}
    #initialize the set of visited nodes
    visited = set()
    #initialize the set of unvisited nodes
    unvisited = set(graph.keys())
    #while there are unvisited nodes
    while unvisited:
        #initialize the current node
        current = None
        #for each node in the set of unvisited nodes
        for node in unvisited:
            #if the cost of the path from the start node to the current node is lower than the cost of the path from the start node to the start node
            if node in cost and (current is None or cost[node] < cost[current]):
                #set the current node to the node
                current = node
        #add the current node to the set of visited nodes
        visited.add(current)
        #remove the current node from the set of unvisited nodes
        unvisited.remove(current)
        #for each node in the set of unvisited nodes
        for node in unvisited:
            #if the cost of the path from the start node to the current node is lower than the cost of the path from the start node to the current node
            if current in graph and node in graph[current]:
                #if the cost of the path from the start node to the node is lower than the cost of the path from the start node to the node
                if cost[current] + graph[current][node] < cost.get(node, float('inf')):
                    #set the cost of the path from the start node to the node to the cost of the path from the start node to the current node plus the cost of the edge from the current node to the node
                    cost[node] = cost[current] + graph[current][node]
                    #set the path from the start node to the node to the path from the start node to the current node plus the edge from the current node to the node
                    path[node] = path[current] + [node]
    #return the cost of the path from the start node to the end node
    return cost[end]