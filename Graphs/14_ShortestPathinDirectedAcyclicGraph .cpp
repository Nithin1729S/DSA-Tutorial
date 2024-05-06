#include<bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        void topoSort(int node,vector<pair<int,int>>adj[],int vis[],stack<int>&stk)
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                int v=it.first;
                if(!vis[v])
                {
                    topoSort(v,adj,vis,stk);  
                }
            }
            stk.push(node);
        }

        vector<int>shortestPath(int N,int M,vector<pair<int,int>>adj[])
        {
            int vis[N]={0};
            stack<int>stk;
            for(int i=0;i<N;i++)
            {
                if(!vis[i])
                {
                    topoSort(i,adj,vis,stk);
                }
            }

            vector<int>dist(N,1e9);
            dist[0]=0;
            while(!stk.empty())
            {
                int node=stk.top();
                stk.pop();

                for(auto it:adj[node])
                {
                    int v=it.first;
                    int wt=it.second;
                    if(dist[node]+wt>dist[v])
                    {
                        dist[v]=dist[node]+wt;
                    }
                }
            }


        }
};