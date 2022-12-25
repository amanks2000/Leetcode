class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        vector<int> ans;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        vector<int> prefix(n, 0);
        prefix[0] = nums[0];
        
        for(int i = 1; i < n; i++)
            prefix[i] = nums[i] + prefix[i-1];
        
        for(auto q: queries) {
            int pos = lower_bound(prefix.begin(), prefix.end(), q) - prefix.begin();
            if(pos < n && prefix[pos] == q) pos += 1;
            ans.push_back(pos);
        }
        return ans;
    }
};
