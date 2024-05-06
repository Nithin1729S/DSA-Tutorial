#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool dfsCheck(int node, vector<int> adj[], int vis[], int pathVis[])
    {
        vis[node] = 1;
        pathVis[node] = 1;

        for (auto it : adj[node])
        {
            if (!vis[it])
            {
                if (dfsCheck(it, adj, vis, pathVis) == true)
                {
                    return true;
                }
            }
            else if (pathVis[it])
            {
                return true;
            }
        }

        pathVis[node] = 0;
        return false;
    }

    bool isCyclic(int V, vector<int> adj[])
    {
        int vis[V + 1] = {0}; // Adjusted size for 1-based indexing
        int pathVis[V + 1] = {0}; // Adjusted size for 1-based indexing
        for (int i = 1; i <= V; i++) // Adjusted loop for 1-based indexing
        {
            if (dfsCheck(i, adj, vis, pathVis) == true)
                return true;
        }
        return false;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<int> adj[V + 1]; // Adjusted size for 1-based indexing
    cout << "Enter edges (from to):\n";
    for (int i = 0; i < E; ++i)
    {
        int from, to;
        cin >> from >> to;
        adj[from].push_back(to);
    }

    Solution s;
    if (s.isCyclic(V, adj))
    {
        cout << "Graph contains cycle\n";
    }
    else
    {
        cout << "Graph does not contain cycle\n";
    }

    return 0;
}
