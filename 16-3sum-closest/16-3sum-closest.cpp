class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = nums[0] + nums[1] + nums[n-1];
        for(int i = 0; i < n-2; i++) {
            int lo = i+1, hi = n-1, sum = 0;
            while(lo < hi) {
                sum = nums[i] + nums[lo] + nums[hi];
                if(abs(sum-target) < abs(ans-target)){
                    ans = sum;
                    // cout << nums[i] << " " << nums[lo] << " " << nums[hi] << endl;
                }
                if(sum < target)
                    lo++;
                else
                    hi--;
            }
        }
        return ans;
    }
};