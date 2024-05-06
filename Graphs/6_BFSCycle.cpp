#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
        bool detect(int start,vector<int>adj[],vector<int>vis)
        {
            vis[start]=1;
            queue<pair<int,int>>q;
            q.push({start,-1});
            while(!q.empty())
            {
                int curNode=q.front().first;
                int parNode=q.front().second;
                q.pop();

                for(auto it:adj[curNode])
                {
                    if(!vis[it])
                    {
                        vis[it]=1;
                        q.push({it,curNode});
                    }
                    else if(parNode!=it)
                    {
                        return true;
                    }
                }
            }
            return false;
        }
        bool isCycle(int V,vector<int>adj[])
        {
            vector<int>vis(V,0);
            for(int i=0;i<V;i++)
            {
                if(!vis[i])
                {
                    if(detect(i,adj,vis)) return true;
                }
            }
            return false;

        }
};