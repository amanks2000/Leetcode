#define ll long long

class Solution {
public:
    vector<vector<int>> adj;
    
    ll dfs(int node, vector<int>& vis) {
        if(vis[node]) 
            return 0;
        
        vis[node] = 1;
        ll ans = 1;
        
        for(auto it: adj[node]) 
            ans += dfs(it, vis);
        
        return ans;
    }
    
    long long countPairs(int n, vector<vector<int>>& edges) {
        adj.resize(n);
        for(auto it: edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        
        vector<int> vis(n, 0);
        vector<ll> vec;
        
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                ll sz = dfs(i, vis);
                vec.push_back(sz);
            }
        }
        
        if(vec.size() == 1) return 0;
        ll ans = 0;
        vec.push_back(0);
        
        for(int i = vec.size() - 2; i >= 0; i--) {
            ans += vec[i] * vec[i+1];
            vec[i] = vec[i] + vec[i+1]; 
        }        
        return ans;      
    }
};