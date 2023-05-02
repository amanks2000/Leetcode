class Solution {
public:
    int arraySign(vector<int>& nums) {
        int prod = 1;
        
        for(auto it: nums) {
            if(it < 0) prod *= -1;
            else if(it == 0) prod = 0; 
        }

        if(prod > 0) return 1;
        if(prod < 0) return -1;
        return 0;
    }
};