class Solution {
public:
    bool isPossible(double k, vector<int>& piles, int h) {
        int time = 0;
        for(auto it: piles) {
            time += ceil(it/k);
            if(time > h) return false;
        }
        return time <= h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int s = 1, e = 1e9, ans = 0;
        while(s <= e) {
            int mid = (s + e) >> 1;
            if(isPossible(mid, piles, h)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};