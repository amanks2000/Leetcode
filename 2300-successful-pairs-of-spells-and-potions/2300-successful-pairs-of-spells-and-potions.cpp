class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, 
    long long success) {
        vector<int> ans;
        int n = potions.size();
        sort(potions.begin(), potions.end());

        for(auto i: spells) {
            long long key = ceil(success/(double)i);
            int pos = lower_bound(potions.begin(), potions.end(), key) - potions.begin();
            ans.push_back(n - pos);
        }

        return ans;
    }
};