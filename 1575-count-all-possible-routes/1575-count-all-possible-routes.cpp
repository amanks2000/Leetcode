class Solution {
public:
    int mod = 1e9 + 7, n;
    vector<vector<int>> dp;

    int countRoutes(vector<int>& loc, int start, int finish, int fuel) {
        n = loc.size();
        dp.resize(n, vector<int>(fuel + 1, -1));
        return solve(start, fuel, finish, loc);
    }

    int solve(int ind, int fuel, int dest, vector<int>& nums) {
        if(fuel < 0) return 0;

        if(dp[ind][fuel] != -1) return dp[ind][fuel];
        
        int res = 0;
        if(ind == dest) res = 1;

        for(int i = 0; i < n; i++) {
            if(i == ind) continue;

            int rfuel = fuel - abs(nums[ind] - nums[i]);
            res = (res + solve(i, rfuel, dest, nums)) % mod;
        }
        return dp[ind][fuel] = res;
    }
};