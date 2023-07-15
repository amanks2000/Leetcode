class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int maxValue(vector<vector<int>>& events, int k) {
        n = events.size();
        dp.resize(n, vector<int>(k+1, -1));
        sort(events.begin(), events.end());
        return solve(0, k, events);
    }

    int solve(int ind, int k, vector<vector<int>>& events) {
        if(k == 0 || ind == n) 
            return 0;

        if(dp[ind][k] != -1) return dp[ind][k];

        int notTake = solve(ind + 1, k, events);

        int i = ind + 1;
        while(i < n && events[i][0] <= events[ind][1]) 
            i++;
        int take = events[ind][2] + solve(i, k-1, events);

        return dp[ind][k] = max(take, notTake);
    }
};