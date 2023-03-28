class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        vector<int> dp(n+1, 0);
        vector<int> d = {1, 7, 30};
        
        for(int ind = n-1; ind >= 0; ind--) {
            int res = INT_MAX;

            for(int i = 0; i < 3; i++) {
                int nextPos = lower_bound(days.begin(), days.end(), days[ind] + d[i]) 
                - days.begin();
                res = min(res, costs[i] + dp[nextPos]);
            }
            dp[ind] = res;
        }

        return dp[0];
    }
};