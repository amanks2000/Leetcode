class Solution {
public:
    int n, ans = INT_MAX;

    int distributeCookies(vector<int>& cookies, int k) {
        n = cookies.size();
        vector<int> vec(k, 0);
        solve(0, k, vec, cookies);
        return ans;
    }

    void solve(int ind, int k, vector<int>& vec, vector<int>& nums) {
        if(ind == n) {
            int res = INT_MIN;
            for(auto it: vec)
                res = max(res, it);
            
            ans = min(ans, res);
            return;
        }

        for(int i = 0; i < k; i++) {
            vec[i] += nums[ind]; // give cookie to kth child
            solve(ind + 1, k, vec, nums);
            vec[i] -= nums[ind]; // give cookie to other child
        }
    }
};