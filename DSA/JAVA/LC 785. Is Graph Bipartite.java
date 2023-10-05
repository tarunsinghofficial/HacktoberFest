/* THEORY: What is a biPartite graph?
	- The graph's vertices can be partitioned into two sets, say set A and set B, in such a way that every edge connects a vertex from set A to a vertex from set B.
	- There are no edges that connect vertices within the same set (i.e., no edges from set A to set A or from set B to set B).
	- No Cycles of Odd Length.
	- Bipartite graphs can be colored using only two colors, such that no two adjacent vertices have the same color. This makes them 2-colorable. [we use this fact to tell if the given graph is bipartite or not] */

// using DFS of graph

class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int vis[] = new int[n];

        for (int i = 0; i < n; i++)
            if (vis[i] == 0)
                if (!dfs(i, graph, vis, 1)) return false;
        return true;
    }
    boolean dfs(int ind, int[][] graph, int[] vis, int color) {
        if (vis[ind] != 0) return vis[ind] == color;
        vis[ind] = color;

        for (int i: graph[ind])
            if (!dfs(i, graph, vis, -color)) return false;
        return true;
    }
}
// TC: O(V + 2E), SC: O(V)
// Alternatively, we could have taken a boolean res = true; and for every dfs call we could done bit-wise& operation with the ans and return ans. But the calls in that case would have continued for all the unvisited nodes and would take more time than needed to return the ans in the case when the graph in non-biPartite unless we put another condition inside the loops to check if the (res == false) then return false.



// using BFS of graph

class Solution {
    public boolean isBipartite(int[][] graph) {
        int n = graph.length;
        int color[] = new int[n];

        for (int i = 0; i < n; i++)
            if (color[i] == 0)
                if (!bfs(i, graph, color)) return false;
        return true;
    }
    boolean bfs(int ind, int[][] graph, int[] color) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(ind);
        color[ind] = 1;

        while (!q.isEmpty()) {
            int cur = q.poll();
            for (int i: graph[cur]) {
                if (color[i] != 0) {
                    if (color[i] == color[cur]) return false;
                }
                else {
                    q.offer(i);
                    color[i] = - color[cur];
                }
            }
        }
        return true;
    }
}