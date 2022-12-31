class Solution {
public:
    int m, n;

    int dfs(int i, int j, int cnt, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || vis[i][j] || grid[i][j] == -1)
            return 0;
        if(grid[i][j] == 2) {
            if(cnt == 0) return 1;
            else return 0;
        }

        vis[i][j] = 1;
        int sm1 = dfs(i+1, j, cnt - 1, vis, grid);
        int sm2 = dfs(i, j+1, cnt - 1, vis, grid);
        int sm3 = dfs(i-1, j, cnt - 1, vis, grid);
        int sm4 = dfs(i, j-1, cnt - 1, vis, grid);
        vis[i][j] = 0;
        
        return sm1 + sm2 + sm3 + sm4;
    }

    int uniquePathsIII(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m, vector<int>(n, 0));

        int s, e, cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) cnt++;
                if(grid[i][j] == 1) s = i, e = j; 
            }
        }

        return dfs(s, e, cnt + 1, vis, grid);
    }
};