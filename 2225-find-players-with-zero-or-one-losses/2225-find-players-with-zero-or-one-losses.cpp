class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<vector<int>> ans;
        unordered_map<int, int> won;
        unordered_map<int, int> lost;

        for(auto it: matches) {
            if(!lost[it[0]]) 
                won[it[0]]++;
            if(won[it[1]]) 
                won[it[1]] = 0;
            lost[it[1]]++;
        }
        
        vector<int> v1;
        for(auto it: won) {
            if(it.second != 0) v1.push_back(it.first);
        }         
        vector<int> v2; 
        for(auto it: lost) {
            if(it.second == 1) v2.push_back(it.first);
        }
        sort(v1.begin(), v1.end());
        sort(v2.begin(), v2.end());

        ans.push_back(v1);
        ans.push_back(v2);
        return ans;
    }
};