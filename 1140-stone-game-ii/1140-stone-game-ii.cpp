class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        dp.resize(n + 1, vector<int>(2*n + 1, -1));
        int diff_score = solve(0, 1, piles); // diff = a - b

        int sum = 0; // sum = a + b
        for(auto it: piles) 
            sum += it;
        return (sum + diff_score)/2; // res = (sum + diff)/2
    }

    int solve(int ind, int m, vector<int>& piles) {
        if(ind == n)
            return 0;

        if(dp[ind][m] != -1) return dp[ind][m];
        int ans = INT_MIN, sum = 0, x = 0;

        for(int i = ind; i < ind + 2*m && i < n; i++) {
            sum += piles[i];
            x++;
            ans = max(ans, sum - solve(i+1, max(m, x), piles));
        }
        return dp[ind][m] = ans;
    }
};