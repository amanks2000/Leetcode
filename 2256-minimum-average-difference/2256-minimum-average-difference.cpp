class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        int n = nums.size();
        vector<long long> prefix(n, 0);
        vector<long long> suffix(n, 0);
        
        prefix[0] = nums[0];
        for(int i = 1; i < n; i++)
            prefix[i] = prefix[i-1] + nums[i];
        for(int i = n-2; i >= 0; i--)
            suffix[i] = suffix[i+1] + nums[i+1];
        int ans = 1e9, mini = 0; 

        for(int i = 0; i < n; i++) {
            int avg1 = prefix[i]/(i+1);
            int avg2 = 0;
            if(i != n-1) avg2 = suffix[i]/(n-i-1);
            // cout << avg1 << " " << avg2 << endl;

            if(abs(avg1 - avg2) < ans) {
                ans = abs(avg1 - avg2);
                mini = i;
            }
        }
        return mini;
    }
};