#define pii pair<int, int>

class Solution {
public:
    int numOfMinutes(int n, int headId, vector<int>& manager, vector<int>& informTime) {
        unordered_map<int, vector<int>> mp;

        for(int i = 0; i < n; i++)
            mp[manager[i]].push_back(i);

        queue<pii> q;
        q.push({0, headId});
        int ans = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                int top = q.front().second;
                int time = q.front().first;
                ans = max(ans, time);

                for(auto it: mp[top])
                    q.push({time + informTime[top], it});
                
                q.pop();
            }  
        }
        return ans;
    }
};