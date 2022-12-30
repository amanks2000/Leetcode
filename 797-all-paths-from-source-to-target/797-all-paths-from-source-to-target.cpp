class Solution {
public:
    int n;
    void dfs(int node, vector<vector<int>>& adj, vector<int> path,
    vector<vector<int>>& ans) {
       path.push_back(node);

        if(node == n-1) {
            ans.push_back(path);
            return;
        }
        
        for(auto it: adj[node])
            dfs(it, adj, path, ans);
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<vector<int>> ans;
        vector<int> path;
        
        dfs(0, graph, path, ans);
        return ans;
    }
};