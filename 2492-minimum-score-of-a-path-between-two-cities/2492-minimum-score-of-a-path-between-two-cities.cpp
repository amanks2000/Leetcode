#define pii pair<int, int>

class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<pii> adj[n+1];
        for(auto it: roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        int mini = 1e9;
        queue<pii> q;
        q.push({1e9, 1});

        vector<int> vis(n+1, 0);

        while(!q.empty()) {
            pii top = q.front();
            int node = top.second, w = top.first;
            mini = min(mini, w);
            
            q.pop();
            vis[node] = 1;

            for(auto it: adj[node]) {
                if(vis[it.first]) {
                    mini = min(mini, it.second);
                }
                else q.push({it.second, it.first});
            }
        }
        return mini;
    }
};