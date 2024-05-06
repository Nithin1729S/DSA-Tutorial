#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> dijkstra(int V, vector<vector<pair<int, int>>> &adj, int S)
    {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        vector<int> distTo(V, INT_MAX);
        distTo[S] = 0;
        pq.push({0, S});

        while (!pq.empty())
        {
            int node = pq.top().second;
            int dis = pq.top().first;
            pq.pop();

            for (auto it : adj[node])
            {
                int v = it.first;
                int w = it.second;
                if (dis + w < distTo[v])
                {
                    distTo[v] = dis + w;
                    pq.push({dis + w, v});
                }
            }
        }
        return distTo;
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<vector<pair<int, int>>> adj(V);

    cout << "Enter the edges in the format 'u v weight':" << endl;
    for (int i = 0; i < E; ++i)
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        adj[u].push_back({v, weight});
        adj[v].push_back({u, weight}); // Uncomment this if graph is undirected
    }

    int source;
    cout << "Enter the source vertex: ";
    cin >> source;

    Solution obj;
    vector<int> distances = obj.dijkstra(V, adj, source);

    cout << "Shortest distances from source " << source << ":\n";
    for (int i = 0; i < V; ++i)
    {
        cout << "Vertex " << i << ": " << distances[i] << endl;
    }

    return 0;
}
