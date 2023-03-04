#define ll long long

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        ll res = 0;
        int n = nums.size(), j = 0, i_bad = -1, i_min = -1, i_max = -1;

        while(j < n) {
            if(nums[j] < minK || nums[j] > maxK) {
                i_bad = j;
                i_min = -1, i_max = -1;
            }
                
            if(nums[j] == minK) i_min = j;
            if(nums[j] == maxK) i_max = j;

            // we can start from any index starting from i_bad + 1 to min(i_min, i_max)
            // after we have got both min and max element as minK and maxK
            if(i_min != -1 && i_max != -1) 
                res += max(0, min(i_min, i_max) - i_bad);
            
            j++;
        }
        return res;
    }
};