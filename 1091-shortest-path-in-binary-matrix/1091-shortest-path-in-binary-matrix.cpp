class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<int>> vis(n, vector<int>(n, 0));

        set<pair<int, pair<int, int>> > st; // {distance, position}
        if(grid[0][0]) return -1;
        st.insert({1, {0,0}});
        int ans = INT_MAX;

        while(!st.empty()) {
            auto p = *(st.begin());
            int d = p.first;
            int x = p.second.first;
            int y = p.second.second;
            vis[x][y] = 1;
            st.erase(p);

            if(x == n-1 && y == n-1) ans = min(ans, d);

            vector<int> drow = {-1, 0, +1, 0, -1, +1, -1, +1};
            vector<int> dcol = {0, -1, 0, +1, -1, -1, +1, +1};

            for(int i = 0; i < 8; i++) {
                int posx = x + drow[i];
                int posy = y + dcol[i];
                if(posx >= 0 && posy >= 0 && posx < n && posy < n && 
                grid[posx][posy] == 0 && !vis[posx][posy]) {
                    st.insert({d + 1, {posx, posy}});
                }
            }
        }
        if(ans == INT_MAX) return -1;
        return ans;
    }
};