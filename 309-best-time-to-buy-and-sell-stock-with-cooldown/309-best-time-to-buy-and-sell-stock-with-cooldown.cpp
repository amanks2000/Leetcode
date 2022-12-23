class Solution {
public:
    int n;
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        vector<vector<int>> dp(n+1, vector<int>(3, -1));
        return solve(0, 1, prices, dp);
    }

    int solve(int ind, int flag, vector<int>& prices, vector<vector<int>>& dp) {
        if(ind == n) return 0;
        
        if(dp[ind][flag] != -1) return dp[ind][flag];
        
        int take = 0, notTake = 0;
        // flag = 1 -> buy
        // flag = 0 -> sell
        // flag = 2 -> ignore

        if(flag == 1) {
            take = -prices[ind] + solve(ind + 1, 0, prices, dp);
        }
        else if(flag == 0) {
            take = prices[ind] + solve(ind + 1, 2, prices, dp);
        }

        if(flag == 2) {
            notTake = solve(ind + 1, 1, prices, dp);
        } 
        else {
            notTake = solve(ind + 1, flag, prices, dp);
        }
        return dp[ind][flag] = max(take, notTake);
    }
};