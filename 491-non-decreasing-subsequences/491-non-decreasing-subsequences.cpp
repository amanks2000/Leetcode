class Solution {
public:
    int n;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        n = nums.size();
        vector<int> v;
        set<vector<int>> st;
        solve(0, -101, nums, v, st);

        vector<vector<int>> ans;
        for(auto &it: st)
            ans.push_back(it);
        return ans;
    }

    void solve(int ind, int prev, vector<int>& nums, vector<int>& cur,
    set<vector<int>>& ans) {
        if(ind >= n)
            return;

        if(nums[ind] >= prev) {
            cur.push_back(nums[ind]);
            if(cur.size() > 1) 
                ans.insert(cur);
                
            solve(ind + 1, nums[ind], nums, cur, ans);
            cur.pop_back();  
        }

        solve(ind + 1, prev, nums, cur, ans);
    }
};