#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
    vector<int> rank, parent, size; // Added size vector
public:
    DisjointSet(int n) {
        rank.resize(n + 1, 0);
        size.resize(n + 1, 1); // Corrected initialization, each node initially has size 1
        parent.resize(n + 1);
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
    }

    int findParent(int node) {
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionByRank(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV) return;
        if (rank[parentU] < rank[parentV]) {
            parent[parentU] = parentV;
        } else if (rank[parentV] > rank[parentU]) {
            parent[parentV] = parentU;
        } else {
            parent[parentV] = parentU;
            rank[parentU]++;
        }
    }

    void unionBySize(int u, int v) {
        int parentU = findParent(u);
        int parentV = findParent(v);
        if (parentU == parentV) return;
        if (size[parentU] < size[parentV]) {
            parent[parentU] = parentV;
            size[parentV] += size[parentU]; // Corrected size update
        }
        else {
            parent[parentV] = parentU;
            size[parentU] += size[parentV]; // Corrected size update
        }
    }
};

int main() {
    DisjointSet ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findParent(3)==ds.findParent(7))
    {
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";
    ds.unionByRank(3,7);

    if(ds.findParent(3)==ds.findParent(7))
    {
        cout<<"Same\n";
    }
    else cout<<"Not Same\n";

}
