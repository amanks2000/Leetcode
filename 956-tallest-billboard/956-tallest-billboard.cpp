class Solution {
public:
    int n;
    int dp[20][2*5001];

    int tallestBillboard(vector<int>& rods) {
        n = rods.size();
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, rods);
    }

    int solve(int ind, int sum_diff, vector<int>& rods) {
        if(ind == n) {
            if(sum_diff == 0) return 0;
            return -1e9;
        }

        if(dp[ind][sum_diff+5000] != -1) return dp[ind][sum_diff+5000];

        int sm1 = solve(ind + 1, sum_diff, rods);
        int sm2 = rods[ind] + solve(ind + 1, sum_diff + rods[ind], rods);
        int sm3 = solve(ind + 1, sum_diff - rods[ind], rods);

        return dp[ind][sum_diff+5000] = max(sm1, max(sm2, sm3));
    }
};