#define ll long long

class Solution {
public:
    ll getSum(ll x, ll size) {
        if(x > size) 
            return (x * size) - (size * (size+1)/2);
        else {
            ll sum = x * (x-1)/2;
            ll extraOnes = size - x + 1;
            return sum + extraOnes;
        }
    }

    int maxValue(int n, int index, int maxSum) {
        int s = 0, e = maxSum, ans = 1;
        while(s <= e) {
            int mid = (s + e) >> 1;
            ll lsum = getSum(mid, index);
            ll rsum = getSum(mid, n - index - 1);

            if(lsum + mid + rsum <= maxSum) {
                ans = mid;
                s = mid + 1;
            } 
            else e = mid - 1;
        }
        return ans;
    }
};