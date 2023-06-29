class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int m = grid.size(), n = grid[0].size();

        int si, sj, totalKeys = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == '@')
                    si = i, sj = j;
                if(islower(grid[i][j]))
                    totalKeys++;
            }
        }

        unordered_map<string, int> vis;
        queue<vector<int>> q; // keys_bitmap, numkeys, row, col

        q.push({0, totalKeys, si, sj});
        string tmp = "0 " + to_string(si) + " " + to_string(sj);
        vis[tmp] = 1;
        int cost = 0;

        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};

        while(!q.empty()) {
            int sz = q.size();
            for(int i = 0; i < sz; i++) {
                auto top = q.front();
                int keys = top[0], numKeys = top[1], row = top[2], col = top[3];
                q.pop();

                if(numKeys == 0)
                    return cost;

                for(int k = 0; k < 4; k++) {
                    int n_row = row + delRow[k];
                    int n_col = col + delCol[k];

                    if(n_row < 0 || n_row >= m || n_col < 0 || n_col >= n 
                    || grid[n_row][n_col] == '#')
                        continue;

                    if(isupper(grid[n_row][n_col])) {
                        int pos = grid[n_row][n_col] - 'A';
                        if((keys & (1 << pos)) == 0) continue;
                    }

                    int tkeys = keys, tnum = numKeys;

                    if(islower(grid[n_row][n_col])) {
                        int pos = grid[n_row][n_col] - 'a';
                        if((tkeys & (1 << pos)) == 0) 
                            tnum--;
                        tkeys = tkeys | (1 << pos);
                    }

                    string loc = to_string(tkeys) + " " + to_string(n_row) + " " 
                    + to_string(n_col);

                    if(!vis[loc]) {
                        q.push({tkeys, tnum, n_row, n_col});
                        vis[loc] = 1;
                    }
                }
            }
            cost++;
        }
        return -1;
    }
};