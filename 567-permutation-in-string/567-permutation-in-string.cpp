class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> mp1, mp2;
        for(auto c: s1) {
            mp1[c]++;
        }
        int i = 0, j = 0, n = s2.size(), target = s1.size(), cnt = 0;
        
        while(j < n) {
            char c = s2[j];
            if(mp1.count(c)) {
                if(cnt >= target) {
                    mp2[s2[i]]--;
                    if(mp2[s2[i]] == 0) mp2.erase(s2[i]);
                    cnt--;
                    i++;
                }
                mp2[c]++;
                cnt++;
            }
            else {
                cnt = 0;
                i = j + 1;
                mp2.clear();
            }

            if(mp1 == mp2) return true;
            j++;
        }   
        return false;
    }
};