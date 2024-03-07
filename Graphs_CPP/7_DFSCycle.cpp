#include<bits/stdc++.h>
using namespace std;
class Soloution
{
    public:
        bool dfs(int node,int parent,vector<int>adj[],vector<int>&vis)
        {
            vis[node]=1;
            for(auto adjNode:adj[node])
            {
                if(!vis[adjNode])
                {
                    if(dfs(adjNode,node,adj,vis)==true)
                    {
                        return true;
                    }
                    
                }
                else if(adjNode!=parent) return false;
            }
        }

        bool isCycle(int V,vector<int>adj[])
        {

            //this is for graphs broken into components
            vector<int>vis(V,0);
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    if(dfs(i,-1,adj,vis)==true) return true;
                }
            }
            return false;

        }

};