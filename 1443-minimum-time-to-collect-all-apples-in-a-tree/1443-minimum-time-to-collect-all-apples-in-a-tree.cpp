class Solution {
public:
    vector<vector<int>> adj;

    int dfs(int node, vector<int>& vis, vector<bool>& hasApple) {
        vis[node] = 1;
        int totalTime = 0, time = 0;

        for(auto it: adj[node]) {
            if(vis[it]) continue;
            time = dfs(it, vis, hasApple);

            if(time || hasApple[it]) totalTime += time + 2;
        }

        vis[node] = 0;
        return totalTime;
    }

    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        adj.resize(n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        return dfs(0, vis, hasApple);
    }
};