import java.util.*;
@SuppressWarnings("unchecked")

class dfs_bfs
{
    private int V;
    private LinkedList<Integer> adj[];

    dfs_bfs(int V)
    {
        this.V = V;
        adj = new LinkedList [V];

        for (int i=0; i<V; i++)
        {
            adj[i] = new LinkedList<>();
        }
    }

    void addEdge(int u, int v)
    {
        adj[u].add(v);
        adj[v].add(u);
    }
    void BFS(int start)
    {
        boolean visited[] = new boolean[V];

        Queue<Integer> queue = new LinkedList<>();
        visited[start] = true;

        queue.add(start);

        while(!queue.isEmpty())
        {
            int node = queue.poll();

            System.out.print(node + " ");

            for(int neighbor : adj[node])
            {
                if(!visited[neighbor])
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
        visited[start] = true;

        DFSHepler(start, visited);
        
    }

    void DFSHepler(int node, boolean visited[])
    {
        System.out.print(node + " ");

        for(int neighbor : adj[node])
        {
            if (!visited[neighbor])
            {
                visited[neighbor] = true;
                DFSHepler(neighbor, visited);
            }
        }

    }

    public static void main(String args[])
    {
        dfs_bfs obj = new dfs_bfs(7);

        obj.addEdge(0,1);
        obj.addEdge(0,2);
        obj.addEdge(1,3);
        obj.addEdge(1,4);
        obj.addEdge(4,5);
        obj.addEdge(4,6);

        System.out.println("DFS Traversal:");
        obj.DFS(0);


        System.out.println();
        System.out.println("BFS Traversal:");
        obj.BFS(0);
    }
}