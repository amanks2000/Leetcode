class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prefix(n);
        vector<int> suffix(n);
        int prod = 1;
        prefix[0] = 1;
        suffix[n-1] = 1;
        
        for(int i = 1; i < n; i++) {
            prod *= nums[i-1];
            prefix[i] = prod;
        }
        
        prod = 1;
        for(int i = n-2; i >= 0; i--) {
            prod *= nums[i+1];
            suffix[i] = prod;
        }
        for(int i = 0; i < n; i++) 
            nums[i] = prefix[i]*suffix[i];
        
        return nums;
    }
};