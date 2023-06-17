class Solution {
public:
    int n1, n2;
    vector<vector<int>> dp;

    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
        n1 = arr1.size(), n2 = arr2.size();
        sort(arr2.begin(), arr2.end());

        dp.resize(n1 + n2 + 1, vector<int>(n1, -1));
        int res = solve(n1 + n2, 0, arr1, arr2);

        if(res == INT_MAX) return -1;
        return res;
    }

    int solve(int pind, int ind, vector<int>& arr1, vector<int>& arr2) {
        if(ind == n1) return 0;

        if(dp[pind][ind] != -1) return dp[pind][ind];

        int prev;
        if(pind == n1 + n2) prev = -1;
        else if(pind >= n1) prev = arr2[pind - n1];
        else prev = arr1[pind];

        int notChange = INT_MAX, change = INT_MAX;

        if(arr1[ind] > prev) 
            notChange = solve(ind, ind + 1, arr1, arr2);
        
        int pos = upper_bound(arr2.begin(), arr2.end(), prev) - arr2.begin();
        if(pos < n2) {
            int res = solve(n1 + pos, ind + 1, arr1, arr2);
            if(res != INT_MAX) change = 1 + res;
        }
        
        return dp[pind][ind] = min(notChange, change);
    }
};