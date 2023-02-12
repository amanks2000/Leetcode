class Solution {
public:
    long long ans = 0, n;
    long long dfs(int node, int seats, vector<int>& vis, vector<int> *adj) {
        vis[node] = 1;
        int people = 1;

        for(auto it: adj[node]) {
            if(!vis[it]) {
                people += dfs(it, seats, vis, adj);
            }
        }

        int cars = people / seats;
        if(people % seats) cars += 1;
        if(node != 0) ans += cars;

        return people;
    }

    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        n = roads.size() + 1;
        vector<int> adj[n];
        for(auto it: roads) {
            int u = it[0], v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int> vis(n + 1, 0);
        long long people = dfs(0, seats, vis, adj);
        return ans;
    }
};