class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int res = 0, cur = 1;
        for(auto it: arr) {
            while(cur < it) {
                res = cur;
                cur++;
                k--;
                if(k == 0) return res;
            }
            cur++;
        }
        while(k > 1) {
            cur++;
            k--;
        }
        return cur;
    }
};