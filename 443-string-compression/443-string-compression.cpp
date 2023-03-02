class Solution {
public:
    int compress(vector<char>& chars) {
        int i = 0, n = chars.size(), ans = 0, cnt = 1;
        char prev = chars[0];
        vector<char> vec;

        while(i < n) {
            while(i+1 < n && chars[i+1] == prev) {
                cnt++;
                i++;
            }
            vec.push_back(prev);
            if(cnt > 1) {
                string s = to_string(cnt);
                for(auto c: s)
                    vec.push_back(c);
                ans += s.size();
            }
            ans++;
            if(i+1 < n) prev = chars[i+1];
            cnt = 1;
            i++;
        }
        chars = vec;
        return ans;
    }
};