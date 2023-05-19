class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0); // 1->colorA, -1->colorB
        queue<int> q;
        
        for(int i = 0; i < n; i++) {
            // Traverse each node individually for multiple connected components
            q.push(i);

            if(color[i]) continue; // if node visited continue
            color[i] = 1;

            while(!q.empty()) {
                int node = q.front();
                q.pop();

                for(auto next: graph[node]) {
                    if(!color[next]) {
                        color[next] = -color[node];
                        q.push(next);
                    }
                    else if(color[next] == color[node]) return false;
                }
            }
        }
        return true;
    }
};