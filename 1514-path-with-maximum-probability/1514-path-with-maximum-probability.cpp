#define pii pair<double, int>

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& sprob, int start, int end) {
        vector<vector<pii>> adj(n); // ith -> {prob, node}

        for(int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back({sprob[i], edges[i][1]});
            adj[edges[i][1]].push_back({sprob[i], edges[i][0]});
        }
        vector<double> dist(n, 0);

        priority_queue<pii> pq; // wt, node
        pq.push({1.0, start});
        dist[start] = 1;
        
        while(!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            int node = top.second;
            double prob = top.first;
            
            if(node == end) return prob;

            for(auto it: adj[node]) {
                int child = it.second;
                double newProb = prob * (it.first);

                if(newProb > dist[child]) {
                    dist[child] = newProb;
                    pq.push({newProb, child});
                }
            }
        }
        return 0;
    }
};