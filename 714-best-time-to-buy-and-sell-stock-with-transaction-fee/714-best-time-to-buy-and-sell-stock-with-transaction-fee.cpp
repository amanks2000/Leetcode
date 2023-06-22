class Solution {
public:
    int n;
    // vector<vector<int>> dp;

    int maxProfit(vector<int>& prices, int fee) {
        n = prices.size();
        // dp.resize(n, vector<int>(2, -1));
        // return solve(0, 0, fee, prices);
        
        vector<int> cur(2, 0), next(2, 0);

        for(int ind = n-1; ind >= 0; ind--) {
            for(int flag = 1; flag >= 0; flag--) {
                int res = next[flag];

                if(!flag) {
                    int buy = -prices[ind] + next[1]; // 1->sell, 0->buy
                    res = max(res, buy);
                }
                else {
                    int sell = prices[ind] - fee + next[0];
                    res = max(res, sell);
                }
                cur[flag] = res;
            }
            next = cur;
        }
        return cur[0];
    }

    // int solve(int ind, int flag, int fee, vector<int>& prices) {
    //     if(ind == n)
    //         return 0;

    //     if(dp[ind][flag] != -1) return dp[ind][flag];

    //     int res = solve(ind + 1, flag, fee, prices);

    //     if(!flag) {
    //         int buy = -prices[ind] + solve(ind + 1, 1, fee, prices);
    //         res = max(res, buy);
    //     }
    //     else {
    //         int sell = prices[ind] - fee + solve(ind + 1, 0, fee, prices);
    //         res = max(res, sell);
    //     }
    //     return dp[ind][flag] = res;
    // }
};