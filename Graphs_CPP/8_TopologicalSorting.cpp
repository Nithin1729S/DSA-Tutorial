#include<bits/stdc++.h>
using namespace std;
class Solution
{
    private:
        void dfs(int node,int vis[],stack<int>&stk,vector<int>adj[] )
        {
            vis[node]=1;
            for(auto it:adj[node])
            {
                if(!vis[it]) dfs(it,vis,stk,adj);
            }
            stk.push(node);
        }
    public:
        vector<int>toposort(int V,vector<int>adj[])
        {
            int vis[V]={0};
            stack<int>stk;
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    dfs(i,vis,stk,adj);
                }
            }
            vector<int>ans;
            while(!stk.empty())
            {
                ans.push_back(stk.top());
                stk.pop();
            }
            return ans;
        }
};