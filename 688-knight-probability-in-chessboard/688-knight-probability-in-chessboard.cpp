class Solution {
public:
    vector<int> delRow, delCol;
    vector<vector<vector<double>>> dp;

    double knightProbability(int n, int k, int row, int column) {
        if(k == 0 && row < n && column < n)
            return 1.0;

        dp.resize(n, vector<vector<double>>(n, vector<double>(k+1, -1)));

        delRow = {-2, -2, -1, -1, +1, +1, +2, +2};
        delCol = {-1, +1, -2, +2, -2, +2, -1, +1};

        return solve(row, column, k, n);
    }

    double solve(int row, int col, int k, int n) {
        if(row < 0 || col < 0 || row >= n || col >= n) return 0;
        if(k == 0) return 1;

        if(dp[row][col][k] != -1) return dp[row][col][k];

        double res = 0;

        for(int i = 0; i < 8; i++) {
            int drow = row + delRow[i];
            int dcol = col + delCol[i];

            res += solve(drow, dcol, k-1, n)/8;
        }
        return dp[row][col][k] = res;
    }

};