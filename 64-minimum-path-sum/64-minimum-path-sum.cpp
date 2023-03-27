class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<long long>> dp(m, vector<long long>(n, -1));
        
        dp[0][0] = grid[0][0];
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int down = INT_MAX, right = INT_MAX;
                if(i > 0) down = dp[i-1][j];
                if(j > 0) right = dp[i][j-1];
                if(i != 0 || j != 0)
                    dp[i][j] = grid[i][j] + min(down, right);
            }
        }
        int ans = dp[m-1][n-1];
        return ans;
    }
};