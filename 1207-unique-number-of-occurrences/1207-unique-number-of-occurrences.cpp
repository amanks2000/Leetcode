class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto it: arr) {
            mp[it]++;
        }
        unordered_map<int, int> oc;
        for(auto it: mp) {
            if(oc.count(it.second) > 0) return false;
            oc[it.second] = it.first;
        }
        return true;
    }
};