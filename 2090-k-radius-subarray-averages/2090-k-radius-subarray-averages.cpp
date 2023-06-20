class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n, -1);
        int pos = k, i = 0, j = 0;
        long long sum = 0;

        while(j < n) {
            sum += nums[j];

            if(j - i == 2*k) {
                ans[pos] = sum/(2*k + 1);
                pos++;
                sum -= nums[i];
                i++;
            }
            j++;
        }
        return ans;
    }
};