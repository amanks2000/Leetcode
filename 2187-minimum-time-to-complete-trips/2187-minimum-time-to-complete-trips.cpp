#define ll long long

class Solution {
public:
    bool isPossible(ll x, vector<int>& time, int totalTrips) {
        ll trips = 0;
        for(auto it: time) {
            trips += (x/(ll)it);
            
            if(trips >= totalTrips)
                return true;
        }
        return false;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        ll s = 1, e = 1e15, ans = 0;
        while(s <= e) {
            ll mid = (s + e) >> 1;
            if(isPossible(mid, time, totalTrips)) {
                ans = mid;
                e = mid - 1;
            }
            else s = mid + 1;
        }
        return ans;
    }
};