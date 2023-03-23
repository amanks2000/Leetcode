class DisjointSet {
public:
    vector<int> size, parent;

    DisjointSet(int n) {
        size.resize(n+1, 1);
        parent.resize(n+1);
        for(int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node) {
        if(node == parent[node])
            return node;

        // Path Compression
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v) {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if(pu == pv) return;

        if(size[pu] < size[pv]) {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }

};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        // Return number of components in graph - 1
        DisjointSet ds(n);
        if(connections.size() < n-1) return -1;

        for(auto it: connections) {
            ds.unionBySize(it[0], it[1]);
        }
        int cnt = 0;
        // calculating number of connected components
        for(int i = 0; i < n; i++) {
            if(ds.parent[i] == i) cnt++;
        }
        return cnt - 1;
    }
};