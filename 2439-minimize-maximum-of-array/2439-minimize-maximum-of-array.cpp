class Solution {
public:
    bool isPossible(int x, vector<int>& nums) {
        int n = nums.size();
        long long next, cur = nums[0];

        for(int i = 0; i < n-1; i++) {
            if(cur > x) return false;
            next = nums[i+1];
            next -= (x - cur);
            cur = next;
        }

        if(cur > x) return false;
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int s = 0, e = 1e9 + 2, ans = e;

        while(s <= e) {
            int mid = (s + e) >> 1;
            if(isPossible(mid, nums)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};