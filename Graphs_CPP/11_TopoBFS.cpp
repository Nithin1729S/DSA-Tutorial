#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> topo(int V, vector<int> adj[])
    {
        int indegree[V + 1] = {0}; // Adjusted size for 1-based indexing

        for (int i = 1; i <= V; i++) // Adjusted loop for 1-based indexing
        {
            for (auto it : adj[i])
            {
                indegree[it]++;
            }
        }
        queue<int> q;

        for (int i = 1; i <= V; i++) // Adjusted loop for 1-based indexing
        {
            if (indegree[i] == 0)
            {
                q.push(i);
            }
        }
        vector<int> topo;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            topo.push_back(node);
            // removing indegree of node
            for (auto it : adj[node])
            {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }
        return topo;
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
    vector<int> topologicalOrder = s.topo(V, adj);

    cout << "Topological Order: ";
    for (int node : topologicalOrder)
    {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
