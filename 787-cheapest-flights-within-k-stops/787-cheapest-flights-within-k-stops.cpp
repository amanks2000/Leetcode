class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, 
    int k) {
        vector<pair<int, int>> adj[n];
        for(auto v: flights) {
            int from = v[0], to = v[1] , price = v[2];
            adj[from].push_back({to, price});
        }
        vector<int> dist(n, INT_MAX);
        queue<pair<int, pair<int, int>> > q; // stops, node, price

        q.push({0, {src, 0}});
        dist[src] = 0;

        while(!q.empty()) {
            auto top = q.front();
            int stops = top.first;
            int node = top.second.first;
            int d = top.second.second;
            // cout << stops << " " << node << " " << d << endl;
            q.pop();

            for(auto p: adj[node]) {
                int newNode = p.first;
                int newDist = p.second + d;

                if(stops < k || (stops == k && newNode == dst)) {
                    if(newDist < dist[newNode]) {
                        dist[newNode] = newDist;
                        q.push({stops+1, {newNode, newDist}});
                    }
                }
            }
        }
        if(dist[dst] == INT_MAX) return -1;
        return dist[dst];
    }
};