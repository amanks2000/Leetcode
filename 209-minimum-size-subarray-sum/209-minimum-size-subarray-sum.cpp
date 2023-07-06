class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0, i = 0, j = 0, n = nums.size(), res = INT_MAX;

        while(j < n) {
            sum += nums[j];

            while(sum >= target) {
                res = min(res, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }
        
        if(res == INT_MAX) return 0;
        return res;
    }
};