#define ll long long

class Solution {
public:
    ll totalCost(int req, vector<int>& nums, vector<int>& cost) {
        ll res = 0;
        for(int i = 0; i < nums.size(); i++) {
            res += (ll)(abs(nums[i] - req)) * (ll)(cost[i]);
        }
        return res;
    }

    long long minCost(vector<int>& nums, vector<int>& cost) {
        int s = 1, e = 1e6;
        ll ans = INT_MAX;

        while(s <= e) {
            int mid = (s + e) >> 1;
            ll left = totalCost(mid, nums, cost);
            ll right = totalCost(mid + 1, nums, cost);

            if(left <= right) e = mid - 1;
            else s = mid + 1;
            ans = min(left, right);
        }
        return ans;
    }
};