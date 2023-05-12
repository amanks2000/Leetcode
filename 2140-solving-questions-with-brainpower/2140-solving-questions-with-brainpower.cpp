#define ll long long

class Solution {
public:
    int n;
    vector<ll> dp;

    ll mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        dp.resize(n + 1, -1);
        return solve(0, questions);
    }

    ll solve(int ind, vector<vector<int>>& questions) {
        if(ind >= n) return 0;

        if(dp[ind] != -1) return dp[ind];
        
        ll notTake = solve(ind + 1, questions);
        ll take = questions[ind][0] + solve(ind + questions[ind][1] + 1, questions);

        return dp[ind] = max(take, notTake);
    }
};