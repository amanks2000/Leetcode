class DisjointSet
{
public:
    vector<int> parent;

    DisjointSet(int n)
    {
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

        if (pv < pu)
            parent[pu] = pv;
        else
            parent[pv] = pu;
    }
};

class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        DisjointSet ds(26);
        int n = s1.size();

        for(int i = 0; i < n; i++) {
            ds.unionBySize(s1[i] - 'a', s2[i] - 'a');
        }

        string ans = "";
        for(auto c: baseStr) {
            int ch = ds.findUParent(c - 'a');
            ans += (ch + 'a');
        }
        return ans;
    }
};