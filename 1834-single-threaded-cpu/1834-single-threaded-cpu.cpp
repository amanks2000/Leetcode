#define pii pair<int, int>
#define ll long long

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        priority_queue <pii, vector<pii>, greater<pii>> pq;
        int n = tasks.size(), i = 0;

        vector<vector<int>> v;
        for(auto it: tasks) {
            vector<int> arr{it[0], it[1], i};
            v.push_back(arr);
            i++;
        }

        sort(v.begin(), v.end());
        i = 0;
        ll time = 0;

        while(i < n || !pq.empty()) {
            if(!pq.empty()) {
                pii top = pq.top();
                pq.pop();
                time += top.first;
                ans.push_back(top.second);
            }

            if(pq.empty() && i < n && time < v[i][0]) {
                time = v[i][0];
                continue;
            } 

            while(i < n && time >= v[i][0]){
                pq.push({v[i][1], v[i][2]});
                i++;
            }
        }

        return ans;
    }
};