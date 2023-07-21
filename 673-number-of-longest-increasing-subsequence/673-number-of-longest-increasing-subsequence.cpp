class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size(), maxi = 0;
        vector<int> dp(n, 1), count(n, 1);

        for(int cur = 0; cur < n; cur++) {
            for(int prev = 0; prev < cur; prev++) {
                if(nums[cur] > nums[prev] && dp[prev] + 1 > dp[cur]) {
                    dp[cur] = dp[prev] + 1;
                    // inherit previous count
                    count[cur] = count[prev];
                }
                else if(nums[cur] > nums[prev] && dp[prev] + 1 == dp[cur])
                    count[cur] += count[prev]; // series of same LIS size
            }
            maxi = max(maxi, dp[cur]);
        }
        
        int res = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)
                res += count[i];
        }
        return res;
    }
};