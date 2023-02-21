class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int s = 0, e = n-1, mid;

        while(s <= e) {
            mid = (s + e) >> 1;
            if((mid - s) % 2 == 0) {
                if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]) 
                    e = mid;
                else if(mid + 1 < n && nums[mid + 1] == nums[mid]) 
                    s = mid;  
                else return nums[mid];
            }
            else {
                if(mid - 1 >= 0 && nums[mid - 1] == nums[mid]) 
                    s = mid + 1;
                else if(mid + 1 < n && nums[mid + 1] == nums[mid]) 
                    e = mid - 1;  
                else return nums[mid];
            }              
        }
        return nums[n-1];
    }
};