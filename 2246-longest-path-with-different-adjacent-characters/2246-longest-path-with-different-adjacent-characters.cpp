class Solution {
public:
    vector<vector<int>> adj;
    vector<int> dist;

    void dfs(int node, string& s, int& ans) {
        dist[node] = 1;

        for(auto it: adj[node]) {
            dfs(it, s, ans);

            if(s[node] != s[it]) {
                ans = max(ans, dist[it] + dist[node]);
                dist[node] = max(dist[node], dist[it] + 1);
            }
        }
    }

    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        adj.resize(n);
        dist.resize(n, 0);

        for(int i = 1; i < n; i++) 
            adj[parent[i]].push_back(i);

        int ans = 1;
        dfs(0, s, ans);
        return ans;
    }
};