#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> shortestPath(vector<vector<int>> adj, int N, int src)
    {
        vector<int> dist(N, 1e9);
        dist[src] = 0;
        queue<int> q;
        q.push(src);
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (auto it : adj[node])
            {
                if (dist[node] + 1 < dist[it])
                {
                    dist[it] = 1 + dist[node];
                    q.push(it);
                }
            }
        }
        return dist;
    }
};

int main()
{   
    int n, m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<vector<int>> adj(n + 1);
    cout << "Enter the edges (u v):" << endl;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    Solution sol;
    
    vector<int> res = sol.shortestPath(adj, n + 1, start);
    cout << "Shortest paths from vertex " << start << ":" << endl;
    for (int i = 1; i <= n; ++i)
    {
        cout << "Distance to vertex " << i << ": " << res[i] << endl;
    }
    
    return 0;
}
