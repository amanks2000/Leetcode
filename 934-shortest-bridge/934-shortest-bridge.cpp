class Solution {
public:
    int n;
    void markIsland(int i, int j, int mark, vector<vector<int>>& vis, 
    vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= n || j >= n || vis[i][j] || grid[i][j] == 0)
            return;

        vis[i][j] = mark;

        markIsland(i, j+1, mark, vis, grid);
        markIsland(i+1, j, mark, vis, grid);
        markIsland(i, j-1, mark, vis, grid);
        markIsland(i-1, j, mark, vis, grid);
    }

    int shortestBridge(vector<vector<int>>& grid) {
        n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));
        int mark = 1;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(!vis[i][j] && grid[i][j]) {
                    markIsland(i, j, mark, vis, grid);
                    mark++;
                }
            }
        }

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
        int res = INT_MAX;

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(vis[i][j] == 2 || vis[i][j] == 0) continue;
                
                queue<vector<int>> q; // i, j, level
                q.push({i, j, 0});

                while(!q.empty()) {
                    auto top = q.front();
                    q.pop();
                    int row = top[0], col = top[1], level = top[2];
                    
                    if(vis[row][col] == 2) {
                        if(dist[row][col] > level) 
                            dist[row][col] = level;
                        res = min(res, level);
                        continue;
                    }

                    for(int k = 0; k < 4; k++) {
                        int n_row = row + delRow[k];
                        int n_col = col + delCol[k];

                        if(n_row < 0 || n_col < 0 || n_row >= n || n_col >= n || 
                        vis[n_row][n_col] == 1 || dist[n_row][n_col] <= level + 1) 
                            continue;

                        dist[n_row][n_col] = level + 1;
                        q.push({n_row, n_col, level + 1});
                    }                    
                }
            }
        }
        return res-1;
    }
};