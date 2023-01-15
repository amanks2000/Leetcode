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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adj(n);
        DisjointSet ds(n);

        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        map<int, vector<int>> nodes;
        for(int i = 0; i < n; i++) 
            nodes[vals[i]].push_back(i);

        vector<int> active(n, 0);
        int res = n;

        for(auto &[_, arr]: nodes) {
            for(auto pos: arr) {
                for(auto it: adj[pos]) {
                    if(active[it]) ds.unionBySize(it, pos);
                }
                active[pos] = 1;
            }

            vector<int> parents;
            for(auto pos: arr) parents.push_back(ds.findUParent(pos));
            sort(parents.begin(), parents.end());

            int cnt = 1;
            for(int i = 1; i < (int)parents.size(); i++) { 
                if(parents[i] != parents[i-1]) {
                    res += cnt * (cnt - 1) / 2;
                    cnt = 1;
                }
                else cnt++;
            }
            res += cnt * (cnt - 1) / 2;
        }

        return res;
    }
};