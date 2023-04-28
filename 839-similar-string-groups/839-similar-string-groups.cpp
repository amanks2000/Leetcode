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
    bool similar(string &a, string& b) {
        if(a.size() != b.size())
            return false;
        
        int diff = 0;
        for(int i = 0; i < a.size(); i++) {
            if(a[i] != b[i]) {
                diff++;
                if(diff > 2) return false;
            }
        }
        return true;
    }


    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        DisjointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(similar(strs[i], strs[j])) 
                    ds.unionBySize(i, j);
            }
        }   

        int res = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUParent(i) == i)
                res++;
        }
        return res;
    }
};