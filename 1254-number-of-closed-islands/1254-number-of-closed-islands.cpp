class Solution {
public:
    int m, n;

    void dfs(int i, int j, vector<vector<int>>& vis, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] || vis[i][j]) 
            return;
        grid[i][j] = 1;
        vis[i][j] = 1;

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};

        for(int k = 0; k < 4; k++) {
            int row = i + delRow[k];
            int col = j + delCol[k];

            dfs(row, col, vis, grid);
        }
    }

    int closedIsland(vector<vector<int>>& grid) {
        m = grid.size(), n = grid[0].size();
        vector<vector<int>> vis(m + 1, vector<int>(n + 1, 0));

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && !grid[i][j] && 
                (i == 0 || j == 0 || i == m-1 || j == n-1)) {
                    dfs(i, j, vis, grid);
                }
            }
        }

        int res = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && !grid[i][j]) {
                    res++;
                    dfs(i, j, vis, grid);
                }
            }
        }
        return res;
    }
};