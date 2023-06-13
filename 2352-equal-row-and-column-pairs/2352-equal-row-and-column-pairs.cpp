class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> inv(n, vector<int>(n));
        for(int j = 0; j < n; j++) {
            vector<int> v;
            for(int i = 0; i < n; i++) v.push_back(grid[i][j]);
            inv.push_back(v);
        }
        
        int cnt = 0;
        for(auto &v1: inv) {
            for(auto &v2: grid) {
                if(v1 == v2) cnt++;
            }
        }
        return cnt;
    }
};