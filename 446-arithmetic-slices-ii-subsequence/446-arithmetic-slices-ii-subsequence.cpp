class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int, int>> mapVector(n);
        int ans = 0;

        for(int i = 1; i < n; i++) {
            for(int j = 0; j < i; j++) {
                long long cd = (long)nums[i] - (long)nums[j]; // cd = common difference of AP
                if(cd <= INT_MIN || cd >= INT_MAX)
                    continue;

                if(mapVector[j][cd] > 0) {
                    ans += mapVector[j][cd];
                    mapVector[i][cd] += mapVector[j][cd] + 1;
                }
                else {
                    mapVector[i][cd] += 1;
                }
            }
        }

        return ans;
    }
};