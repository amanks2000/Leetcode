class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        vector<vector<int>> dp(n1, vector<int>(n2, 0));
        // return memoi(n1-1, n2-1, text1, text2, dp);
        for(int i = 0; i < n1; i++) {
            for(int j = 0; j < n2; j++) {
                if(text1[i] == text2[j]) {
                    dp[i][j] = 1;
                    if(i-1 >= 0 && j-1 >= 0) dp[i][j] += dp[i-1][j-1];
                }

                else {
                    int sm1 = 0, sm2 = 0;
                    if(i - 1 >= 0) sm1 = dp[i-1][j];
                    if(j - 1 >= 0) sm2 = dp[i][j-1];
                    dp[i][j] = max(sm1, sm2);
                }
            }
        }
        return dp[n1-1][n2-1];
    }
};