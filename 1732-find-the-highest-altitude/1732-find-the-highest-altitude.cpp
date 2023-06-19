class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int res = 0, sum = 0;
        for(auto it: gain) {
            sum += it;
            res = max(res, sum);
        }
        return res;
    }
};