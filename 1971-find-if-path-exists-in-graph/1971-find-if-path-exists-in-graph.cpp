class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<int> adj[n];
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> vis(n, 0);
        queue<int> q;
        q.push(source);
        vis[source] = 1;

        while(!q.empty()) {
            int top = q.front();
            q.pop();
            if(top == destination) return true;

            for(auto it: adj[top]) {
                if(!vis[it]) {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return false;
    }
};