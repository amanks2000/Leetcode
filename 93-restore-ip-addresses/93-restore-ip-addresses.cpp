class Solution {
public:
    int n;
    vector<string> restoreIpAddresses(string s) {
        n = s.size();
        vector<string> ans;
        solve(0, s, "", 0, "", ans);
        return ans;
    }

    void solve(int ind, string& s, string num, int dots, string cur, vector<string>& ans) {
        if(dots == 3) {
            string rem = s.substr(ind);

            if(rem.size() == 0 || (rem[0] == '0' && rem.size() > 1))
                return;
            long temp = stol(rem);
            
            if(temp <= 255) {
                cur = cur + rem;
                ans.push_back(cur);
            }
            return;
        } 

        if(ind >= n || (num[0] == '0')) 
            return;

        num += s[ind];
        long temp = stol(num);

        if(temp <= 255) {
            solve(ind + 1, s, num, dots, cur, ans); // not take num in cur
            cur = cur + num + ".";
            solve(ind + 1, s, "", dots + 1, cur, ans); // take num in cur
        }        
        
    }
};