#define ll long long

class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> exist;
        for(auto &s: ideas) exist.insert(s);

        vector<vector<int>> vec(26, vector<int>(26, 0));
        // To calculate value when a string start with ch is replaced with another char CH

        for(auto &s: ideas) {
            char ch = s[0];
            string str = s.substr(1);
            for(int i = 0; i < 26; i++) {
                char CH = 'a' + i;
                string x = CH + str;
                if(exist.find(x) == exist.end()) vec[ch-'a'][i]++;
            }
        }

        ll res = 0;
        for(int first = 0; first < 26; first++) {
            for(int second = 0; second < 26; second++) {
                res += vec[first][second]*vec[second][first];
            }
        }
        return res;
    }
};