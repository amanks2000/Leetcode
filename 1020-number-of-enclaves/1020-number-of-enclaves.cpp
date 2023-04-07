class Solution {
public:
    int M, N;
    vector<vector<int>> vis{501, vector<int>(501, 0)};
    void dfs(int i, int j, vector<vector<int>>& grid) {
        if(i < 0 || j < 0 || i >= M || j >= N || vis[i][j] || grid[i][j] == 0)
            return;
        vis[i][j] = 1;
        dfs(i-1, j, grid);
        dfs(i+1, j, grid);
        dfs(i, j-1, grid);
        dfs(i, j+1, grid);
    }

    int numEnclaves(vector<vector<int>>& grid) {
        M = grid.size(); N = grid[0].size();
        // vector<vector<int>> vis(M, vector<int>(N, 0));
        int count = 0;
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 1 && !vis[i][j] && (i==0 || j==0 || i==M-1 || j==N-1)) 
                    dfs(i, j, grid);      
            }
        }
        for(int i = 0; i < M; i++) {
            for(int j = 0; j < N; j++) {
                if(grid[i][j] == 1 && !vis[i][j]) count++;
            }
        }
        return count;
    }
};