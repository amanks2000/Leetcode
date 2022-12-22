class Solution {
public:
    int dist = 0;
    int countNodes(int node, int level, vector<int>& vis, vector<int> adj[], 
    vector<int>& count) {
        if(vis[node])
            return 0;
        vis[node] = 1;
        dist += level;

        count[node] = 1;
        for(auto it: adj[node])
            count[node] += countNodes(it, level+1, vis, adj, count);

        return count[node];
    }

    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<int> ans(n);
        vector<int> adj[n];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        vector<int> count(n, 0);
        int rootCount = countNodes(0, 0, vis, adj, count);
        ans[0] = dist;

        queue<int> q;
        q.push(0);
        vis.clear();
        vis.resize(n, 0);

        while(!q.empty()) {
            int size = q.size();

            for(int i = 0; i < size; i++) {
                int top = q.front();
                q.pop();
                vis[top] = 1;

                for(auto it: adj[top]) {
                    if(!vis[it]) {
                        q.push(it);
                        ans[it] = ans[top] - count[it] + (n - count[it]);
                    }
                }
            }
        }
        
        // for(int i = 1; i < n; i++) {
        //     ans[i] = dist - count[i] + (n - count[i]);
        //     // ans[i] = root_dist - closer_nodes + further_nodes
        // }
        return ans;
    }
};