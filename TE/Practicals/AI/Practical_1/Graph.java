import java.util.*;
@SuppressWarnings("unchecked")
class Graph 
{
    private int V;
    private LinkedList<Integer> adj[];

    Graph(int V) 
    {
        this.V = V;

        adj = new LinkedList[V];

        // Initialize each LinkedList
        for (int i = 0; i < V; i++) 
        {
            adj[i] = new LinkedList<>();
        }
    }

    void addEdge(int u, int v) {
        adj[u].add(v);
        adj[v].add(u);
    }

    void BFS(int start) 
    {
        boolean visited[] = new boolean[V];
        Queue<Integer> queue = new LinkedList<>();

        visited[start] = true;
        queue.add(start);

        while (!queue.isEmpty()) 
        {
            int node = queue.poll();
            System.out.print(node + " ");

            for (int neighbor : adj[node]) 
            {
                if (!visited[neighbor]) 
                {
                    visited[neighbor] = true;
                    queue.add(neighbor);
                }
            }
        }
    }

    void DFS(int start)
    {
        boolean visited[] = new boolean[V];
        DFSHelper(start, visited);
    }

    void DFSHelper(int node, boolean visited[])
    {
        visited[node] = true;
        System.out.print(node + " ");

        for (int neighbor : adj[node]) 
        {
            if (!visited[neighbor]) 
            {
                DFSHelper(neighbor, visited);
            }
        }
    }

    public static void main(String args[]) 
    {
        Graph g = new Graph(5);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 3);
        g.addEdge(1, 4);

        System.out.println("BFS starting from 0:");
        g.BFS(0);

        System.out.println("\nDFS starting from 0:");
        g.DFS(0);
    }
}