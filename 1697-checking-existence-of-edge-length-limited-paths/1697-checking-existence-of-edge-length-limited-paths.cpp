class DisjointSet
{
public:
    vector<int> size, parent;

    DisjointSet(int n)
    {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;

        // Path Compression
        return parent[node] = findUParent(parent[node]);
    }

    void unionBySize(int u, int v)
    {
        int pu = findUParent(u);
        int pv = findUParent(v);
        if (pu == pv)
            return;

        if (size[pu] < size[pv])
        {
            size[pv] += size[pu];
            parent[pu] = pv;
        }
        else
        {
            size[pu] += size[pv];
            parent[pv] = pu;
        }
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, 
    vector<vector<int>>& queries) {
        DisjointSet ds(n);
        // sorting edges according to their weights
        sort(edgeList.begin(), edgeList.end(), [&](vector<int>&a,vector<int>&b) {
            return a[2] < b[2];
        }); 

        vector<vector<int>> qs; // limit, pos, u, v
        for(int i = 0; i < queries.size(); i++) {
            vector<int> v(4);
            v[0] = queries[i][2], v[1] = i;
            v[2] = queries[i][0], v[3] = queries[i][1];
            qs.push_back(v);
        }

        // sorting queries according to their limit
        sort(qs.begin(), qs.end());
        vector<bool> ans(qs.size(), false);
        int pos = 0;

        for(auto &it: qs) {
            int limit = it[0], ind = it[1];
            int u = it[2], v = it[3];
            
            // union edges that have weights less than limit
            while(pos < edgeList.size() && edgeList[pos][2] < limit) {
                ds.unionBySize(edgeList[pos][0], edgeList[pos][1]);
                pos++;
            }
            if(ds.findUParent(u) == ds.findUParent(v))
                ans[ind] = true;
        }
        return ans;
    }
};
