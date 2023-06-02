#define ll long long

class Solution {
public:
    ll distance(ll x1, ll y1, ll x2, ll y2) {
        return pow(x2 - x1, 2) + pow(y2 - y1, 2);
    }

    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size(), ans = 0;

        for(int start = 0; start < n; start++) {
            queue<int> q;
            vector<int> vis(n, 0);

            q.push(start);
            vis[start] = 1;
            int res = 1;

            while(!q.empty()) {
                auto top = q.front();
                ll x1 = bombs[top][0], y1 = bombs[top][1], r1 = bombs[top][2];
                q.pop();

                for(int i = 0; i < n; i++) {
                    if(vis[i]) continue;
                    int x2 = bombs[i][0], y2 = bombs[i][1], r2 = bombs[i][2];
                    ll dist = distance(x1, y1, x2, y2);

                    if(dist <= r1 * r1) {
                        q.push(i);
                        vis[i] = 1;
                        res++;
                    }
                }
            }
            ans = max(ans, res);
        }
        return ans;
    }
};