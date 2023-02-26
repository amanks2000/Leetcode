class Solution {
public:
    int minDistance(string s1, string s2) {
        int n = s1.size(), m = s2.size();
        
        vector<int> prev(m+1, 0);
        for(int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for(int i = 1; i <= n; i++) {
            vector<int> cur(m+1, 0);
            cur[0] = i;
            for(int j = 1; j <= m; j++) {
                if(s1[i-1] == s2[j-1]) 
                    cur[j] = prev[j-1];
                else {
                    int insert = 1 + cur[j-1];
                    int remove = 1 + prev[j];
                    int replace = 1 + prev[j-1];
                    cur[j] = min(insert, min(remove, replace));
                }
            }
            prev = cur;
        }
        
        return prev[m];
    }
    // int solve(int i, int j, string s1, string s2, vector<vector<int>>& dp) 
    // {
    //     if(i == -1)
    //         return j+1;
    //     if(j == -1)
    //         return i+1;

    //     if(dp[i][j] != -1)
    //         return dp[i][j];

    //     if(s1[i] == s2[j])
    //         return solve(i-1, j-1, s1, s2, dp);
    //     else {
    //         int insert = 1 + solve(i, j-1, s1, s2, dp);
    //         int remove = 1 + solve(i-1, j, s1, s2, dp);
    //         int replace = 1 + solve(i-1, j-1, s1, s2, dp);

    //         return dp[i][j] = min(insert, min(remove, replace));
    //     }
    // }
};