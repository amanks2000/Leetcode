class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> vec1(26, 0);
        vector<int> vec2(26, 0);
        for(auto c: p) vec1[c - 'a']++;

        vector<int> ans;
        int i = 0, j = 0, n = s.size(), si = -1, cnt = 0, target = p.size();

        while(j < n) {
            char c = s[j], last = s[i];
            if(vec1[c - 'a']) {
                if(cnt == target) {
                    vec2[last - 'a']--;
                    i++;
                    cnt--;
                }
                si = i;
                vec2[c - 'a']++;
                cnt++;
            }
            else {
                cnt = 0;
                i = j+1;
                si = -1;
                vec2.clear();
                vec2.resize(26, 0);
            }

            if(vec1 == vec2)
                ans.push_back(si);
        
            j++;
        }
        return ans;
    }
};