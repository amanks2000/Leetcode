class Solution {
public:
    int n, m, mod = 1e9 + 7;
    vector<vector<long>> dp;
    vector<vector<long>> freq;

    int numWays(vector<string>& words, string target) {
        n = target.size(), m = words[0].size();
        dp.resize(m, vector<long>(n, -1));
        freq.resize(m, vector<long>(26, 0)); 
        // freq[i][j] -> at ith index count of jth character

        for(int i = 0; i < words.size(); i++) {
            for(int j = 0; j < m; j++) {
                int k = words[i][j] - 'a';
                freq[j][k]++;
            }
        }
        return solve(0, 0, target);
    }

    long solve(int i, int j, string& target) {
        if(j == n) return 1;
        if(i == m) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int k = target[j] - 'a';
        long res = 0;
        res = (res + solve(i + 1, j, target)) % mod;
        res = (res + (freq[i][k] * solve(i + 1, j + 1, target)) % mod) % mod;
        
        return dp[i][j] = res;
    }
};