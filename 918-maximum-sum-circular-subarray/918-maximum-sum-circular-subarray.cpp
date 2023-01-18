class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        int maxi = nums[0], curMax = 0, mini = nums[0], curMin = 0;
        int n = nums.size(), sum = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];

            curMax = max(curMax + nums[i], nums[i]);
            maxi = max(maxi, curMax);

            curMin = min(curMin + nums[i], nums[i]);
            mini = min(mini, curMin);
        }

        if(maxi <= 0) return maxi;
        return max(maxi, sum - mini);    
    }
};