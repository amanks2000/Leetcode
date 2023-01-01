class Solution {
public:
    bool wordPattern(string pattern, string s) {
        int n = s.size(), j = 0;;
        string temp = "";
        unordered_map<char, string> mp;
        unordered_map<string, char> rev;

        for(int i = 0; i < n; i++) {
            if(s[i] == ' ') {
                
                if(mp.count(pattern[j])) {
                    if(mp[pattern[j]] != temp) return false;
                }
                else if(rev.count(temp)) {
                    if(rev[temp] != pattern[j]) return false;
                }
                else {
                    mp[pattern[j]] = temp;
                    rev[temp] = pattern[j];
                }
                j++;
                temp = "";
            }
            else temp += s[i];
        }
        
        if(temp != "") {
            if(mp.count(pattern[j])) {
                if(mp[pattern[j]] != temp) return false;
            }
            else if(rev.count(temp)) {
                if(rev[temp] != pattern[j]) return false;
            }
            j++;
        }

        if(j != pattern.size()) return false;
        return true;
    }
};