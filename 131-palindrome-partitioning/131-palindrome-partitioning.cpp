class Solution {
public:
    int N;
    vector<vector<string>> partition(string s) {
        N = s.size();
        vector<vector<string>> ans;
        vector<string> v;
        solve(0, s, v, ans);
        return ans;
    }
    void solve(int cur, string& s, vector<string> v, vector<vector<string>>& ans) {
        if(cur >= N) {
            ans.push_back(v);
            return;
        }

        for(int k = cur; k < N; k++) {
            string s1 = s.substr(cur, k - cur + 1);
            string s2 = s1;
            reverse(s2.begin(), s2.end());
            if(s1 == s2) {
                v.push_back(s1);
                solve(k+1, s, v, ans);
                v.pop_back();
            }
        }

    }
};