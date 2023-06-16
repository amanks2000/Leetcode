#define ll long long

class Solution {
public:
    int mod = 1e9 + 7;
    vector<vector<ll>> pascal;

    ll solve(vector<int>& nums) {
        int n = nums.size();
        if(n <= 2) return 1;

        vector<int> left, right;
        for(int i = 1; i < n; i++) {
            if(nums[i] < nums[0]) left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }

        ll lres = solve(left);
        ll rres = solve(right); 

        // result = n-1_C_left * solve(left) * solve(right)
        // pascal's triangle is use to calculate nCr to reduce time complexity

        ll ans = (((pascal[n-1][left.size()] * lres) % mod) * rres) % mod;
        return ans;
    }

    int numOfWays(vector<int>& nums) {
        int n = nums.size();
        pascal.resize(n+1);

        for(int i = 0; i <= n; i++) {
            pascal[i].resize(i+1, 1);
            for(int j = 1; j < i; j++) {
                pascal[i][j] = (pascal[i-1][j-1] + pascal[i-1][j]) % mod; 
            }
        }
        return (solve(nums) % mod) - 1;
    }
};