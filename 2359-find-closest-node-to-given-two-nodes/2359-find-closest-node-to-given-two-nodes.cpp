class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        unordered_map<int, int> mp;
        int n = edges.size();
        
        vector<int> vis(n, 0);
        int node = node1, d = 1, ans = 1e9, ind = -1;
        
        while(node != -1 && !vis[node]) {
            // cout << node << " " << d << endl;
            vis[node] = 1;
            mp[node] = d;
            d++;
            node = edges[node];
        }
        
        for(auto &it: vis) it = 0;
        node = node2, d = 1;
        
        while(node != -1 && !vis[node]) {
            vis[node] = 1;
            
            if(mp[node]) {
                int res = max(d, mp[node]);
                if(res <= ans) {
                    if(res == ans) ind = min(ind, node);
                    else ind = node;
                    ans = res;
                }
            }
            
            d++;
            node = edges[node];
        }
        
        return ind;
    }
};