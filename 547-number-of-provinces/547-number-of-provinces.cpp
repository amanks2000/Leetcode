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
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DisjointSet ds(n);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(isConnected[i][j]) 
                    ds.unionBySize(i, j);
            }
        }
        int cnt = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUParent(i) == i) // if node is itself its ultimate parent
                cnt++;
        }
        return cnt;
    }
};