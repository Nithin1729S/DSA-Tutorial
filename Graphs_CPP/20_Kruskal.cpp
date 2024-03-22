#include <bits/stdc++.h>
using namespace std;

class DisjointSet
{
    vector<int> rank, parent, size;

public:
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        size.resize(n + 1);
        for (int i = 1; i <= n; i++)
        {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUPar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUPar(parent[node]);
    }

    void unionByRank(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] < rank[ulp_v])
        {
            parent[ulp_u] = ulp_v;
        }
        else if (rank[ulp_v] < rank[ulp_u])
        {
            parent[ulp_v] = ulp_u;
        }
        else
        {
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }

    void unionBySize(int u, int v)
    {
        int ulp_u = findUPar(u);
        int ulp_v = findUPar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v])
        {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else
        {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution
{
public:
    pair<int, vector<pair<int, int>>> spanningTree(int V, vector<pair<int, pair<int, int>>> *adj)
    {
        vector<pair<int, pair<int, int>>> edges;
        for (int i = 1; i <= V; i++)
        {
            for (auto it : adj[i])
            {
                int adjNode = it.first;
                int wt = it.second.first;
                int node = i;

                edges.push_back({wt, {node, adjNode}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(), edges.end());
        int mstWt = 0;
        vector<pair<int, int>> mstEdges;
        for (auto it : edges)
        {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;

            if (ds.findUPar(u) != ds.findUPar(v))
            {
                mstWt += wt;
                mstEdges.push_back({u, v});
                ds.unionBySize(u, v);
            }
        }

        return {mstWt, mstEdges};
    }
};

int main()
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    vector<pair<int, pair<int, int>>> adj[V + 1];
    cout << "Enter edges in the format (from to weight):\n";
    for (int i = 0; i < E; ++i)
    {
        int from, to, weight;
        cin >> from >> to >> weight;
        adj[from].push_back({to, {weight, 0}});
        adj[to].push_back({from, {weight, 0}}); // For undirected graph
    }

    Solution s;
    pair<int, vector<pair<int, int>>> result = s.spanningTree(V, adj);
    int mstWeight = result.first;
    vector<pair<int, int>> mstEdges = result.second;

    cout << "Minimum Spanning Tree weight: " << mstWeight << endl;
    cout << "Edges chosen in the MST:\n";
    for (auto edge : mstEdges)
    {
        cout << edge.first << " - " << edge.second << endl;
    }

    return 0;
}
