class Solution {
public:
    int mod = 1e9 + 7;
    int countGoodStrings(int low, int high, int zero, int one) {
        vector<int> dp(high + 1, 0);
        dp[0] = 1;
        
        for(int i = 1; i <= high; i++) {
            if(i - zero >= 0) {
                dp[i] += dp[i-zero];
                dp[i] %= mod;
            }
            if(i - one >= 0) {
                dp[i] += dp[i-one];
                dp[i] %= mod;
            }
        }
        
        int ans = 0;
        for(int i = low; i <= high; i++) {
            ans += dp[i];
            ans %= mod;
        }
        return ans;
    }
    
//     int solve(int n, int zero, int one, vector<int>& dp) {
//         if(n == 0)
//             return 1;
//         if(n < 0)
//             return 0;
        
//         if(dp[n] != -1)
//             return dp[n];
        
//         int sm1 = solve(n - zero, zero, one, dp) % mod;
//         int sm2 = solve(n - one, zero, one, dp) % mod;
        
//         return dp[n] = (sm1 + sm2) % mod;
//     }
};