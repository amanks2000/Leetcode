class Solution {
public:
    int m, n, mod = 1e9 + 7;
    vector<vector<int>> dp;
    
    int dfs(int i, int j, vector<vector<int>>& grid) {
        if(dp[i][j] != -1)
            return dp[i][j];

        vector<int> delx = {-1, 0, +1, 0};
        vector<int> dely = {0, -1, 0, +1};
        int ans = 1;

        for(int k = 0; k < 4; k++) {
            int x = i + delx[k], y = j + dely[k];
            if(x < 0 || x >= m || y < 0 || y >= n)
                continue;

            if(grid[i][j] < grid[x][y]) {
                ans = (ans + dfs(x, y, grid)) % mod;
            }
        }
        return dp[i][j] = ans;
    }   
    
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        dp.resize(m+1, vector<int>(n+1, -1));

        int ans = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                ans = (ans + dfs(i, j, grid)) % mod;
            }
        }
        return ans;
    }
};