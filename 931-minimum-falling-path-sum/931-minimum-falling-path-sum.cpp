class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size(), ans = INT_MAX;
        
        vector<int> prev(n, 0);
        
        for(int i = 0; i < m; i++) {
            vector<int> curr(n, 0);
            for(int j = 0; j < n; j++) {
                if(i == 0)
                    curr[j] = matrix[0][j];
                else {
                    int sm1 = INT_MAX, sm2 = INT_MAX, sm3 = INT_MAX;
                    if(j-1 >= 0) sm1 = prev[j-1];
                    sm2 = prev[j];
                    if(j+1 < n) sm3 = prev[j+1];
                    curr[j] = matrix[i][j] + min(sm1, min(sm2, sm3));
                }
                if(i == m-1)
                    ans = min(ans, curr[j]);
            }
            prev = curr;
        }
        return ans;
    }
};