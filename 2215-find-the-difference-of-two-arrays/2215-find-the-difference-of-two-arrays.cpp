class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp1, mp2;
        vector<int> v1, v2;
        for(auto it: nums1) mp1[it]++;

        for(auto it: nums2) {
            if(mp1[it] == 0) {
                mp1[it]++;
                v1.push_back(it);
            }
            mp2[it]++;
        }

        for(auto it: nums1) {
            if(mp2[it] == 0){
                mp2[it]++;
                v2.push_back(it);
            } 
        }
        vector<vector<int>> ans(2);
        ans = {v2, v1};
        return ans;
    }
};