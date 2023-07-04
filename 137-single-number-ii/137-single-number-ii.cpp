class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size(), num = 0;

        for(int i = 0; i < 32; i++) {
            int cnt = 0;
            for(auto it: nums) {
                if((it >> i) & 1)
                    cnt++;
            }
            if(cnt % 3) // one bit is of single number since other numbers form group of 3
                num |= (1 << i);
        }
        return num;
    }
};