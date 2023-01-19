class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, sum = 0;

        for(auto x: nums) {
            sum += x;
            int rem = sum % k;
            if(rem < 0) rem = rem + k; // if remainder is negative add k to it

            if(mp[rem]) ans += mp[rem];
            mp[rem]++;
        }

        return ans;
    }
};