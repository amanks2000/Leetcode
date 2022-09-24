class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size(), lo = 0, hi = n-1, i = n-1;
        int maxi = 0;
        
        while(lo < hi) {
            maxi = max(maxi, min(height[lo], height[hi]) * i);
            if(height[lo] > height[hi])
                hi--;
            else
                lo++;
            i--;
        }
        return maxi;
    }
};