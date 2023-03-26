class Solution {
public:
    int maxi = -1;
    void dfs(int node, vector<int>& vis, vector<int>& path, vector<int>& edges) {
        if(node == -1) return;

        if(vis[node]) {
            int c = -1;
            for(int i = 0; i < path.size(); i++) {
                if(path[i] == node) {
                    c = i;
                    break;
                }
            }
            if(c != -1) maxi = max(maxi, (int)path.size() - c);
            return;
        }

        vis[node] = 1;
        path.push_back(node);
        dfs(edges[node], vis, path, edges);
        path.pop_back();
    }

    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> vis(n, 0);
        vector<int> path;

        for(int i = 0; i < n; i++) {
            if(!vis[i]) dfs(i, vis, path, edges);
        }

        return maxi;
    }
};