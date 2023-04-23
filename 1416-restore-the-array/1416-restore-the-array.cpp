class Solution {
public:
    int mod = 1e9 + 7, n;
    vector<int> dp;

    int numberOfArrays(string s, int k) {
        n = s.size();
        dp.resize(n + 1, -1);

        return solve(0, k, s);
    }
    
    int solve(int ind, int k, string& s) {
        if(ind == n) return 1;

        if(dp[ind] != -1) return dp[ind];
        long num = 0, res = 0;

        for(int i = ind; i < n && i < ind + 10; i++) {
            num = num * 10 + (s[i] - '0');

            if(i < n - 1 && s[i + 1] == '0') continue;
            if(num > k) break;
            
            res = (res + solve(i + 1, k, s)) % mod;
        }
        return dp[ind] = res;
    }
};