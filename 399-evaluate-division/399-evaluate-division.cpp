#define pii pair<double, string>

class Solution {
public:
    int n;
    unordered_map<string, int> mp;

    double bfs(string num, string den, vector<vector<string>>& eq, vector<double>& val) {
        if(mp.count(num) == 0)
            return -1;
        if(num == den) return 1.0;
        
        for(int i = 0; i < n; i++) {
            auto v = eq[i];
            if(v[0] != num && v[1] != num) continue;

            queue<pii> q;
            vector<int> vis(n, 0);

            if(v[0] == num) q.push({val[i], v[1]});
            else q.push({1.0/val[i], v[0]});
            vis[i] = 1;

            while(!q.empty()) {
                auto top = q.front();
                q.pop();
                if(top.second == den) 
                    return top.first;
                
                for(int j = 0; j < n; j++) {
                    if((eq[j][0] != top.second && eq[j][1] != top.second) || vis[j]) 
                        continue;

                    vis[j] = 1;
                    double f = val[j];
                    string nx = eq[j][1];

                    if(eq[j][0] != eq[j][1] && eq[j][1] == top.second) {
                        f = 1.0/f;
                        nx = eq[j][0];
                    }
                    q.push({top.first * f, nx});
                }
            }
        }
        return -1.0;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, 
    vector<vector<string>>& queries) {
        n = equations.size();
        vector<double> ans;

        for(auto &v: equations) {
            for(auto &s: v)
                mp[s] = 1;
        }

        for(auto &q: queries) {
            double res = bfs(q[0], q[1], equations, values);
            ans.push_back(res);
        }
        return ans;
    }
};