class Solution {
public:
    int jump(vector<int>& nums) {
        int  n = nums.size();
        int l = 0, r = 0, count = 0;
        while(r < n-1) 
        {
            int furthermost = -1;
            for(int i = l; i <= r; i++) 
                furthermost = max(furthermost, i + nums[i]);
            l = r + 1;
            r = furthermost;
            count++;
        }
        return count;
    }
};