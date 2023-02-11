#define pii pair<int, int>

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, 
    vector<vector<int>>& blue) {
        vector<int> ans(n, -1);
        vector<vector<pii>> adj(n);
        // 1->red, 2->blue

        for(auto it: red) {
            adj[it[0]].push_back({1, it[1]});
        }
        for(auto it: blue) {
            adj[it[0]].push_back({2, it[1]});
        }

        queue<pair<int, pii>> q; // node, level, color
        vector<vector<int>> vis(n, vector<int>(3, 0));
        q.push({0, {0, 0}});

        while(!q.empty()) {
            int node = q.front().first;
            int level = q.front().second.first;
            int color = q.front().second.second;
            q.pop();

            for(auto it: adj[node]) {
                int nextColor = it.first;
                int nextNode = it.second; 
                if((color == 0 || nextColor != color) && !vis[nextNode][nextColor]) {
                    q.push({nextNode, {level + 1, nextColor}});
                    vis[nextNode][nextColor] = 1;
                    if(ans[nextNode] == -1) ans[nextNode] = level + 1;
                }
            }
        }
        ans[0] = 0;
        return ans;
    }
};