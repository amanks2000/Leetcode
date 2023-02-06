class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        // since nums <= 1000, therefore nums can be stored in a 10 bit integer
        // therfore we can use another 10 bits of the num to store other number
        for(int i = n; i < 2*n; i++) {
            int temp = nums[i] << 10;
            nums[i-n] |= temp; // last 10 bits original x val, 2nd last 10 bits y val
        }

        int delim = pow(2, 10) - 1;

        for(int i = n-1; i >= 0; i--) {
            int x_val = nums[i] & delim;
            int y_val = nums[i] >> 10;
            nums[2*i] = x_val;
            nums[2*i + 1] = y_val;
        }

        return nums;
    }
};