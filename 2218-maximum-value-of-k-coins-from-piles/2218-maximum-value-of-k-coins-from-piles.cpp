class Solution {
public:
    vector<vector<int>> dp;
    int n;
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        n = piles.size();
        dp.resize(n + 1, vector<int>(k + 1, -1));
        return solve(0, k, piles);
    }

    int solve(int ind, int k, vector<vector<int>>& piles) {
        if(k == 0 || ind == n) 
            return 0;
        
        if(dp[ind][k] != -1) return dp[ind][k];

        int sm1 = solve(ind + 1, k, piles);
        int sm2 = 0, sum = 0;

        for(int j = 0; j < piles[ind].size(); j++) {
            sum += piles[ind][j];
            if(k - j - 1 >= 0)
                sm2 = max(sm2, sum + solve(ind + 1, k - j - 1, piles));
        }
        return dp[ind][k] = max(sm1, sm2);
    }
};