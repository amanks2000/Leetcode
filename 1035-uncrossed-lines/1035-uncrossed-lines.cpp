class Solution {
public:
    int n1, n2;
    vector<vector<int>> dp;

    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        n1 = nums1.size(), n2 = nums2.size();
        dp.resize(n1, vector<int>(n2, -1));

        int ans = solve(0, 0, nums1, nums2);
        return ans;
    }

    int solve(int i, int j, vector<int>& nums1, vector<int>& nums2) {
        if(i == n1 || j == n2)
            return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int notTake = solve(i + 1, j, nums1, nums2);
        int take = 0, pos = j;

        while(pos < n2) {
            if(nums2[pos] != nums1[i])
                pos++;
            else break;
        }
        if(pos < n2) take = 1 + solve(i + 1, pos + 1, nums1, nums2);

        return dp[i][j] = max(take, notTake);
    }
};