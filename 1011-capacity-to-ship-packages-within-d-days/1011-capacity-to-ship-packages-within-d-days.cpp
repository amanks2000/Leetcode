class Solution {
public:
    int n;
    bool isPossible(int x, int days, vector<int>& prefix) {
        int cnt = 0, prev = 0;
        for(int i = 0; i < n; i++) {
            if(prefix[i] - prev > x) {
                cnt++;
                prev = prefix[i-1];
            }
        }
        
        return cnt < days;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        n = weights.size();
        int maxi = weights[0];
        vector<int> prefix(n);
        prefix[0] = weights[0];

        for(int i = 1; i < n; i++) {
            prefix[i] = prefix[i-1] + weights[i];
            maxi = max(weights[i], maxi);
        }
        
        int l = maxi, r = 1e8, ans;
        while(l <= r) {
            int mid = (l + r) >> 1;
            if(isPossible(mid, days, prefix)) {
                r = mid - 1;
                ans = mid;
            }
            else l = mid + 1;
        }
        return ans;
    }
};