#define pii pair<int, int>

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto it: nums) mp[it]++;

        priority_queue<pii> pq;
        for(auto &[x, y]: mp) {
            pq.push({y, x});
        }

        vector<int> ans;
        while(k--) {
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};