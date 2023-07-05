class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size(), i = 0, j = 0, flag = 0, res = 0;

        while(j < n) {
            if(nums[j] == 0) {
                if(flag) {
                    while(nums[i] == 1) 
                        i++;
                    i++;                   
                }
                else 
                    flag = 1;
            }
            int sz = j - i;
            res = max(res, sz);
            j++;
        }
        return res; 
    }
};