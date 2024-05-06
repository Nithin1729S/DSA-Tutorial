#include <bits/stdc++.h>
using namespace std;


class DisjointSet
{
    vector<int>size,rank,parent;
    public:
        DisjointSet(int n)
        {
            size.resize(n+1,1);
            rank.resize(n+1,0);
            parent.resize(n+1);
            for(int i=0;i<n;i++)
            {
                parent[i]=i;
            }
        }

        int findParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findParent(parent[node]);
    }

        void unionByRank(int u,int v)
        {
            int pu=findParent(u);
            int pv=findParent(v);
            if(pu==pv) return;
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
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        DisjointSet ds(n);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(isConnected[i][j]==1)
                {
                    ds.unionByRank(i,j);
                }
            }
        }

        int count=0;
        for(int i=0;i<n;i++)
        {
            if(ds.findParent(i)==i)
            {
                count++;
            }
        }
        return count;
    }
};