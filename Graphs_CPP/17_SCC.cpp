//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{   
    private:
        
        
        
        
	public:
	
	void dfs(int node,vector<vector<int>>&adj,vector<int>&vis,stack<int>&stk)
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    dfs(it,adj,vis,stk);
                }
            }
            stk.push(node);
        }
        
        void dfsnorm(int node,vector<vector<int>>&adj,vector<int>&vis)
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it])
                {
                    dfsnorm(it,adj,vis);
                }
            }
        }
	//Function to find number of strongly connected components in the graph.
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code here
        vector<int>vis(V,0);
        stack<int>stk;
        for(int i=0;i<V;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis,stk);
            }
        }
        vector<vector<int>>adjT(V);
        
        for(int i=0;i<V;i++)
        {
            vis[i]=0;
            for(auto it:adj[i])
            {
                adjT[it].push_back(i);
            }
        }
            
        int scc=0;
        while(!stk.empty())
        {
            int node=stk.top();stk.pop();
            if(!vis[node])
            {
                scc++;
                dfsnorm(node,adjT,vis);
            }
        }
        return scc;
        
        
    }
};