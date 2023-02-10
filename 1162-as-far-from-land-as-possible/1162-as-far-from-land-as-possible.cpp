#define pii pair<int, int>

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        int n = grid.size();
        queue<pair<int, pii>> q;
        // Push all elements with value 1 to queue
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j])
                    q.push({0, {i, j}});
            }
        }

        vector<int> delRow = {+1, -1, 0, 0};
        vector<int> delCol = {0, 0, +1, -1};
        int ans = -1;

        while(!q.empty()) {
            int sz = q.size();
            int level = q.front().first;
            if(level) ans = level;

            for(int i = 0; i < sz; i++) {
                int x = q.front().second.first;
                int y = q.front().second.second;
                // cout << x << " " << y << ": " << level << endl;

                for(int k = 0; k < 4; k++) {
                    int row = x + delRow[k];
                    int col = y + delCol[k];
                    if(row < 0 || col < 0 || row >= n || col >= n) continue;

                    if(grid[row][col] == 0) {
                        // not visited member
                        grid[row][col] = 1;
                        q.push({level + 1, {row, col}});
                    }
                }
                q.pop();
            }
        }
        return ans;
    }
};