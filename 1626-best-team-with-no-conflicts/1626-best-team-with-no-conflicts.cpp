#define pii pair<int, int>

class Solution {
public:
    int n;
    vector<vector<int>> dp;

    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<pii> vec;
        n = scores.size();
        dp.resize(n+1, vector<int>(n+1, -1));

        for(int i = 0; i < n; i++) {
            vec.push_back({ages[i], scores[i]});
        }
        sort(vec.begin(), vec.end());
        return solve(0, -1, vec);
    }

    int solve(int ind, int prev, vector<pii>& vec) {
        if(ind == n) return 0;

        if(dp[ind][prev + 1] != -1) return dp[ind][prev + 1];

        if(prev != -1 && vec[prev].first != vec[ind].first 
        && vec[prev].second > vec[ind].second) {
            return dp[ind][prev + 1] = solve(ind + 1, prev, vec);
        }

        int take = vec[ind].second + solve(ind + 1, ind, vec);
        int notTake = solve(ind + 1, prev, vec);
        return dp[ind][prev + 1] = max(take, notTake);
    }
};