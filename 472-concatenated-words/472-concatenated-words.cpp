class Solution {
public:
    unordered_map<string, int> mp;
    vector<vector<int>> dp;

    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto &s: words) 
            mp[s]++;
        vector<string> ans;

        for(auto &s: words) {
            dp.clear();
            dp.resize(s.size() + 1, vector<int>(31, -1));
            if(solve(0, 0, s.size(), s))
                ans.push_back(s);
        }
        return ans;
    }

    bool solve(int ind, int cnt, int n, string& s) {
        if(ind >= n) {
            if(cnt >= 2) return true;
            return false;
        }

        if(dp[ind][cnt] != -1)
            return dp[ind][cnt];

        string temp = "";
        bool ans = false, sm = false;

        for(int i = ind; i < n; i++) {
            temp += s[i];
            if(mp[temp]) sm = solve(i + 1, cnt + 1, n, s);
            ans |= sm;
        }
        return dp[ind][cnt] = ans;
    }
};