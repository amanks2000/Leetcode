class Solution {
public:
    int mod = 1e9+7, m, n;
    vector<vector<vector<int>>> dp;

    int ways(vector<string>& pizza, int k) {
        m = pizza.size(), n = pizza[0].size();
        vector<vector<int>> prefix(m+1, vector<int>(n+1, 0));
        // prefix[i][j] -> sum of all elements in matrix starting at (i, j) to end

        for(int i = m-1; i >= 0; i--) {
            for(int j = n-1; j >= 0; j--) {
                prefix[i][j] = prefix[i+1][j] + prefix[i][j+1] - prefix[i+1][j+1] 
                + (pizza[i][j] == 'A');
            }
        }
        dp.resize(m+1, vector<vector<int>>(n+1, vector<int>(k+1, -1)));
        return solve(0, 0, k-1, prefix);
    }

    int solve(int i, int j, int k, vector<vector<int>>& prefix) {
        if(prefix[i][j] == 0) return 0;
        if(k == 0) return 1;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        int ans = 0;
        // horizontal cut
        for(int r = i + 1; r < m; r++) {
            if(prefix[i][j] - prefix[r][j] > 0)
                ans = (ans + solve(r, j, k-1, prefix)) % mod;
        }

        // vertical cut
        for(int c = j + 1; c < n; c++) {
            if(prefix[i][j] - prefix[i][c] > 0)
                ans = (ans + solve(i, c, k-1, prefix)) % mod;
        }
        return dp[i][j][k] = ans;
    }
};