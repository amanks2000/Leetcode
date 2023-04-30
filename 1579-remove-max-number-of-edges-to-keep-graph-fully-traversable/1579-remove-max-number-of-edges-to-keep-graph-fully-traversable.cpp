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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet ds1(n);
        DisjointSet ds2(n);

        // sorting according to type, so that first we union edges that both can
        // traverse simultaneusly
        sort(edges.begin(), edges.end(), greater<vector<int>>());

        int res = 0;
        for(auto &it: edges) {
            int type = it[0];
            int u = it[1], v = it[2];

            if(type == 1) {
                if(ds1.findUParent(u) == ds1.findUParent(v))
                    res++;
                else
                    ds1.unionBySize(u, v);
            }
            else if(type == 2) {
                if(ds2.findUParent(u) == ds2.findUParent(v))
                    res++;
                else
                    ds2.unionBySize(u, v);
            }
            else {
                if(ds1.findUParent(u) == ds1.findUParent(v) && 
                ds2.findUParent(u) == ds2.findUParent(v))
                    res++;
                else {
                    ds1.unionBySize(u, v);
                    ds2.unionBySize(u, v);
                }
            }
        }

        int cnt1 = 0, cnt2 = 0;
        for(int i = 1; i <= n; i++) {
            if(ds1.findUParent(i) == i) cnt1++;
            if(ds2.findUParent(i) == i) cnt2++;
        }
        
        if(cnt1 > 1 || cnt2 > 1) return -1;
        return res;
    }
};