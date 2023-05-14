class Solution {
public:
    int n;
    vector<vector<int>> dp;
    
    int maxScore(vector<int>& nums) {
        n = nums.size();
        dp.resize(n/2 + 1, vector<int>((1 << n), -1));
        return solve(1, 0, nums);
    }

    int solve(int op, int mask, vector<int>& nums) {
        if(op > n/2) return 0;
        if(dp[op][mask] != -1) return dp[op][mask];

        int ans = 0;
        for(int i = 0; i < n; i++) {
            if((mask >> i) & 1) continue;

            for(int j = i + 1; j < n; j++) {
                if((mask >> j) & 1) continue;

                int newMask = (1 << i) | (1 << j) | mask;
                int res = op*__gcd(nums[i], nums[j]) + solve(op + 1, newMask, nums);
                ans = max(res, ans);
            }
        }
        return dp[op][mask] = ans;
    }
};