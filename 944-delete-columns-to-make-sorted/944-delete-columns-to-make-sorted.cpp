class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), cnt = 0;
        
        for(int j = 0; j < (int)strs[0].size(); j++) {
            for(int i = 1; i < n; i++) {
                if(strs[i-1][j] > strs[i][j]) {
                    cnt++;
                    break;
                }
            }
        }
        
        return cnt;
    }
};