class Solution {
public:
    int n, m;
    unordered_map<string, int> pos;
    vector<vector<int>> dp, choice;

    vector<int> smallestSufficientTeam(vector<string>& req_skills, 
    vector<vector<string>>& people) {
        n = people.size(), m = req_skills.size();
        
        dp.resize(n, vector<int>((1 << m), -1));
        choice.resize(n, vector<int>((1 << m), 0));

        for(int i = 0; i < m; i++)
            pos[req_skills[i]] = i;

        vector<int> peopleMask(n, 0);
        for(int i = 0; i < n; i++) {
            int mask = 0;
            for(auto &s: people[i])
                mask |= (1 << pos[s]);

            peopleMask[i] = mask;
        }

        int res = solve(0, 0, peopleMask);
        vector<int> ans;

        for(int ind = 0, mask = 0; ind < n; ind++) {
            if(choice[ind][mask]) {
                ans.push_back(ind);
                mask |= peopleMask[ind];
            }
            if(mask + 1 == (1 << m))
                break;
        }
        return ans;
    }

    int solve(int ind, int mask, vector<int>& peopleMask) {
        if(mask + 1 == (1 << m))
            return 0;

        if(ind == n)
            return 1e7;

        if(dp[ind][mask] != -1) return dp[ind][mask];

        int take = 1 + solve(ind + 1, mask | peopleMask[ind], peopleMask);
        int notTake = solve(ind + 1, mask, peopleMask);

        if(take < notTake)
            choice[ind][mask] = 1;

        return dp[ind][mask] = min(take, notTake);
    }
};