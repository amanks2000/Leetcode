class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        unordered_map<int, int> mp;
        int ans = n, maxCount = 0;
        
        for(auto it: trust) {
            mp[it[1]]++;   
            if(mp[it[1]] > maxCount) {
                maxCount = mp[it[1]];
                ans = it[1];
            }
        }

        if(maxCount != n-1) 
            return -1;

        for(auto it: trust) {
            if(it[0] == ans)
                return -1;
        }
        return ans;
    }
};