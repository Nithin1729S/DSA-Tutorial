#include<bits/stdc++.h>
using namespace std;

int main() {   
    int n, m;
    cin >> n >> m;
    
    vector<pair<int, int>> adj[n + 1]; // Vector of pairs to store edges and weights
    
    for(int i = 0; i < m; i++) {
        int u, v, w; // vertices and weight
        cin >> u >> v >> w;
        // for undirected graph
        adj[u].push_back({v, w}); // Edge from u to v with weight w
        adj[v].push_back({u, w}); // Edge from v to u with weight w (assuming undirected graph)
    }
    
    return 0;
}
