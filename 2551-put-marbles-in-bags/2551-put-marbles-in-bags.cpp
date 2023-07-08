#define ll long long

class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        int n = weights.size();
        ll maxi = weights[0] + weights[n-1];
        ll mini = maxi;

        vector<int> vec;
        for(int i = 1; i < n; i++) {
            vec.push_back(weights[i-1] + weights[i]);
        }
        sort(vec.begin(), vec.end());
        n = vec.size();

        for(int i = 0; i < k-1; i++) mini += vec[i];
        for(int i = n-1; i >= n-k+1; i--) maxi += vec[i];

        return maxi - mini;
    }
};