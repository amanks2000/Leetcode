class Solution {
public:
    int n;
    vector<int> dp;
    bool canJump(vector<int>& nums) {
        n = nums.size();
        for(int i = 0; i <= n; i++)
            dp.push_back(-1);
        
        return solve(0, nums);
    }

    int solve(int index, vector<int>& nums) {
        if(index == n-1)
            return 1;
        if(index >= n || nums[index] == 0)
            return 0;
        
        if(dp[index] != -1)
            return dp[index];

        for(int i = 1; i <= nums[index]; i++) {
            int smallAns = solve(index + i, nums);
            if(smallAns) return dp[index] = 1;
        }
        return dp[index] = 0;
    }
};