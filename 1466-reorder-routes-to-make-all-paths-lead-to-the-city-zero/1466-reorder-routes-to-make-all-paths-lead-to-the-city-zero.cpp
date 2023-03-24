#define pii pair<int, int>

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        set<pii> st;
        vector<vector<int>> adj(n);

        for(auto &it: connections) {
            st.insert({it[0], it[1]});
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);
        int res = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                int top = q.front();
                vis[top] = 1;
                q.pop();

                for(auto v: adj[top]) {
                    if(!vis[v]) {
                        q.push(v);
                        if(st.find({v, top}) == st.end())
                            res++;
                    }
                }
            }
        }
        return res;
    }
};