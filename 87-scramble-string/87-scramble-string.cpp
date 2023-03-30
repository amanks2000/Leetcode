class Solution {
public:
    unordered_map<string, unordered_map<string, bool>> mp;
    bool isScramble(string s1, string s2) {
        return solve(s1, s2);
    }

    bool solve(string s1, string s2) {
        if(s1 == s2) return true;

        if(mp.count(s1) && mp[s1].count(s2)) return mp[s1][s2];

        vector<int> count(26, 0);
        int n = s1.size();

        for(int i  = 0; i < n; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for(int i = 0; i < 26; i++) {
            if(count[i]) return false;
        }

        for(int i = 1; i < n; i++) {
            // no swap
            if(solve(s1.substr(0, i), s2.substr(0, i)) && 
            solve(s1.substr(i), s2.substr(i))) return mp[s1][s2] = true;

            // swap
            if(solve(s1.substr(0, i), s2.substr(n-i)) && 
            solve(s1.substr(i), s2.substr(0, n-i))) return mp[s1][s2] = true;
        }
        return mp[s1][s2] = false;
    }
};