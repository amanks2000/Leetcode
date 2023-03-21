#define ll long long

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        ll ans = 0, cnt = 0;
        for(auto it: nums) {
            if(it) {
                ans += cnt*(cnt+1)/2;
                cnt = 0;
            }
            else cnt++;
        }
        ans += cnt*(cnt+1)/2;
        return ans;
    }
};