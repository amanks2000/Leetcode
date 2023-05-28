class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int N = cuts.size();
        cuts.insert(cuts.begin(), 0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        vector<vector<int>> dp(N+2, vector<int>(N+2, 0));
        for(int i = N; i >= 1; i--) {
            for(int j = i; j <= N; j++) {
                int mini = INT_MAX;
                for(int k = i; k <= j; k++) {
                    int cost = cuts[j+1] - cuts[i-1] + dp[i][k-1] + dp[k+1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][N];
    }
};