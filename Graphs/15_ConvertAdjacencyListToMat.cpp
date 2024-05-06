#include<bits/stdc++.h>
using namespace std;

int main()
{   
    int n, m;
    cin >> n >> m;
    
    // Create adjacency list
    vector<int> adj[n+1];
    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // Create adjacency matrix
    vector<vector<int>> adjMatrix(n+1, vector<int>(n+1, 0)); // Initialize with zeros

    for(int i = 1; i <= n; i++) {
        for(int j : adj[i]) {
            adjMatrix[i][j] = 1;
            adjMatrix[j][i] = 1; // Since it's an undirected graph, we set both directions
        }
    }

    // Print adjacency matrix
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cout << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
