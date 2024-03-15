#include<bits/stdc++.h>
using namespace std;
class DisjointSet
{
    
    public:
        vector<int>rank,size,parent;
        DisjointSet(int n)
        {
            rank.resize(n+1,0);
            size.resize(n+1,1);
            parent.resize(n);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }
        int findParent(int node)
        {
            if(node==parent[node]) return node;
            return parent[node]=findParent(parent[node]);
        }

        void unionByRank(int u,int v)
        {
            int pu=parent[u];
            int pv=parent[v];
            if(pu==pv) return ;
            if(rank[pu]>rank[pv])
            {
                parent[pv]=pu;
            }
            else if(rank[pv]>rank[pu])
            {
                parent[pu]=pv;
            }
            else
            {
                parent[pu]=pv;
                rank[pv]++;
            }
        }

        void unionBySize(int u,int v)
        {
            int pu=parent[u];
            int pv=parent[v];
            if(pu==pv) return ;
            if(rank[pu]>rank[pv])
            {
                parent[pv]=pu;
                size[pu]+=size[pv];
            }
            else
            {
                parent[pu]=pv;
                size[pv]+=size[pu];
            }
        }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int extra=0;
        for(auto it:connections)
        {
            int u=it[0];
            int v=it[1];
            if(ds.findParent(u)==ds.findParent(v)) extra++;
            else ds.unionByRank(u,v);
        }
        int comp=0;
        for(int i=0;i<n;i++)
        {
            if(ds.parent[i]==i) comp++;
        }
        int res=comp-1;
        if(extra>=res) return res;
        return -1;
    }
};