class Solution {
public:
    unordered_map<int, int> color;

    bool dfs(int node, int parent, vector<int>& vis, vector<int> adj[]) {
        if(vis[node])
            return true;
        vis[node] = 1;

        for(auto it: adj[node]) {
            if(color[it] && color[it] == color[node])
                return false;
            color[it] = color[node] * -1;

            bool sm = dfs(it, node, vis, adj);
            if(!sm) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int> vis(n+1, 0);
        vector<int> adj[n+1];

        for(auto it: dislikes) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                color[i] = 1;
                bool sm = dfs(i, 0, vis, adj);
                if(!sm) return false;
            }
        }
        return true;
    }
};