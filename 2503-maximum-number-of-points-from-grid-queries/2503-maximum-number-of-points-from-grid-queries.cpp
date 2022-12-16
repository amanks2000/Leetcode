class Solution {
public:
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int m = grid.size(), n = grid[0].size();
        vector<int> ans;
        vector<int> temp = queries;

        vector<vector<int>> vis(m ,vector<int>(n, 0));
        set<pair<int, pair<int, int>> > s;
        s.insert({grid[0][0], {0, 0}});
        vis[0][0] = 1;

        sort(queries.begin(), queries.end());
        vector<int> delRow = {-1, 0, +1, 0};
        vector<int> delCol = {0, -1, 0, +1};
        unordered_map<int, int> mp;
        int prev = 0;

        for(auto q: queries) {
            int cnt = 0;
            while(!s.empty() && (*s.begin()).first < q) {
                auto it = *s.begin();
                int val = it.first;   
                int row = it.second.first;
                int col = it.second.second;

                for(int i = 0; i < 4; i++) {
                    int newRow = row + delRow[i];
                    int newCol = col + delCol[i];

                    if(newRow >= 0 && newRow < m && newCol >= 0 && newCol < n 
                    && !vis[newRow][newCol]) {
                        vis[newRow][newCol] = 1;
                        s.insert({grid[newRow][newCol], {newRow, newCol}});
                    }
                }

                s.erase(it);
                cnt++;
            }
            mp[q] = cnt + prev;
            prev = mp[q];
        }

        for(auto it: temp)
            ans.push_back(mp[it]);
        return ans;
    }
};