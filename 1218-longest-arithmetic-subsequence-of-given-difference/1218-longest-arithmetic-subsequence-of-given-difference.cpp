class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> mp;
        int res = 1;
        for(int i = 0; i < arr.size(); i++) {
            mp[arr[i]] = mp[arr[i] - diff] + 1;
            res = max(res, mp[arr[i]]);
        }
        return res;
    }


};