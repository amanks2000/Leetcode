class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans = "";
        int n = strs.size();
        if(n == 1)
            return strs[0];
        int minl = INT_MAX;
        for(int i = 0; i < n; i++) {
            int x = strs[i].size();
            minl = min(minl, x);
        }
        int count = 0;
        for(int i = 0; i < minl; i++) {
            int flag = 0;
            for(int j = 0; j < n-1; j++) {
                if(strs[j][i] != strs[j+1][i]){
                    flag = 1;
                    break;
                }
            }
            if(flag){
                break;
            }
            else {
                ans += strs[0][count++];
                // cout << ans << " " << count << endl;
            }
        }
        return ans;
    }
        
};