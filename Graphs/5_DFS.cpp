#include<bits/stdc++.h>
using namespace std;

class Solution{
public:    
    vector<int>bfsOfGraph(int V, vector<int> adj[], int start)
    {
        int vis[V]={0};
        vis[start]=1;
        queue<int>q;
        q.push(start);
        vector<int>bfs;

        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            bfs.push_back(node);
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
        return bfs;
    }

    void dfs(int node,vector<int>adj[],int vis[],vector<int>&ls)
    {
        vis[node]=1;
        ls.push_back(node);
        for(auto it:adj[node])
        {
            if(!vis[it])
            {
                dfs(it,adj,vis,ls);
            }
        }

    }
    vector<int>dfsOfGraph(int V,vector<int>adj[],int start)
    {
        int vis[V]={0};
        vector<int>ls;
        dfs(start,adj,vis,ls);
        return ls;
        
    }
};


int main()
{   
    int n,m;
    cout << "Enter the number of vertices and edges: ";
    cin >> n >> m;

    vector<int>adj[n+1];
    cout << "Enter the edges (u v):" << endl;
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin>>u>>v;
        //for undirected graph
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    int start;
    cout << "Enter the starting vertex: ";
    cin >> start;

    Solution sol;
    
    vector<int>res=sol.dfsOfGraph(n, adj, start); // Using dfsOfGraph instead of bfsOfGraph
    cout << "DFS Traversal: ";
    for(auto i:res)
    {
        cout<<i<<" ";
    }
    
    return 0;
}


