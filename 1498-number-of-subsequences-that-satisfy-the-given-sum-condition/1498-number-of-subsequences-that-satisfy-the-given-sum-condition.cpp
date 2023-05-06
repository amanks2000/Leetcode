#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;

    ll power(ll x, ll y) {
        ll res = 1;

        while (y > 0) {
            if (y % 2 == 1)
                res = (res * x) % mod ;

            y = y >> 1;
            x = (x * x) % mod;
        }
        return res % mod;
    }

    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0, n = nums.size();

        for(int i = 0; i < n; i++) {
            if(nums[i] * 2 > target) break;
            int pos = upper_bound(nums.begin(), nums.end(), target - nums[i]) 
            - nums.begin();

            int x = pos - i - 1;
            res = (res + power(2, x)) % mod;
        }
        return res;
    }
};