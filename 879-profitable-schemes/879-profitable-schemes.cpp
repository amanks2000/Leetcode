class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<vector<int>>> dp;

    int profitableSchemes(int n, int minProfit, vector<int>& group, 
    vector<int>& profit) {
        int m = group.size();
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(minProfit+1, -1)));
        return solve(0, n, minProfit, group, profit);
    }

    int solve(int ind, int n, int minProfit, vector<int>& group, 
    vector<int>& profit) {
        if(ind >= group.size()) {
            if(minProfit <= 0) return 1;
            return 0;
        }

        if(minProfit <= 0) minProfit = 0;
        if(dp[ind][n][minProfit] != -1) return dp[ind][n][minProfit];

        int take = 0;
        if(n - group[ind] >= 0)
            take = solve(ind+1, n-group[ind], minProfit-profit[ind], group,profit);
        int notTake = solve(ind+1, n, minProfit, group, profit);

        return dp[ind][n][minProfit] = (take + notTake) % mod;
    }
};