class Solution {
public:
    int numRescueBoats(vector<int>& nums, int limit) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int s = 0, e = n-1, res = 0;

        while(s <= e) {
            if(nums[s] + nums[e] <= limit) s++;
            e--;
            res += 1;
        }
        return res;
    }
};