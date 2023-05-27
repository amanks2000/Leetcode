class Solution {
public:
    int n;
    vector<int> dp;
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        dp.resize(n + 1, -1);
        
        int res = solve(0, stoneValue);
        if(res < 0) return "Bob";
        else if(res > 0) return "Alice";
        return "Tie";
    }

    int solve(int i, vector<int>& nums) {
        if(i >= n) return 0;
        if(dp[i] != -1) return dp[i];

        int sum = 0, ans = INT_MIN;
        for(int j = i; j < i + 3 && j < n; j++) {
            sum += nums[j];
            ans = max(ans, sum - solve(j + 1, nums));
        }
        return dp[i] = ans;
    }
};