class Solution {
public:
    bool closeStrings(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        if(m != n) return false;

        unordered_map<char, int> m1;
        unordered_map<char, int> m2;
        string s1 = "", s2 = "";

        for(int i = 0; i < n; i++) {
            if(m1[word1[i]] == 0)
                s1 += word1[i];
            if(m2[word2[i]] == 0)
                s2 += word2[i];
            m1[word1[i]]++;
            m2[word2[i]]++;
        }
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());
        if(s1 != s2) return false;

        for(auto c1: s1) {
            int flag = 0;
            for(auto c2: s2) {
                if(m1[c1] == m2[c2]) {
                    flag = 1;
                    m2[c2] = 0;
                    break;
                }
            }
            if(flag == 0) return false;
        }
        return true;
    }
};