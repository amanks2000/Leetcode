class Solution {
public:
    vector<vector<int>> adj;

    vector<int> dfs(int node, int parent, string& labels, vector<int>& ans) {
        vector<int> count(26, 0);
        count[labels[node] - 'a'] = 1;

        for(auto it: adj[node]) {
            if(it == parent) continue;

            vector<int> childCount = dfs(it, node, labels, ans);

            for(int i = 0; i < 26; i++) count[i] += childCount[i];            
        }

        ans[node] = count[labels[node] - 'a'];
        return count;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        adj.resize(n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> ans(n, 0);
        vector<int> count = dfs(0, -1, labels, ans);

        return ans;
    }
};