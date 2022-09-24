class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {   
        int n = nums.size();
        unordered_map<int, int> map;
        map[0]++;
        int sum = 0, count = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums[i];
            if(map[sum-k]) {
                count += map[sum-k];
            }
            map[sum]++;
        }
        
        return count;
//         int n = nums.size();
        
//         int i = 0, j = 0, sum = 0, count = 0;
//         // variable length sliding window problem         
//         while(j < n) {
//             sum += nums[j];
            
//             if(sum < k) {
//                 j++;
//             }
//             else if(sum == k) {
//                 count++;
//                 j++;
//             }
//             else {
//                 while(sum > k && i <= j) {
//                     sum -= nums[i];
//                     i++;
//                 }
//                 if(sum == k)
//                     count++;
//                 j++;
//             }
//             // cout << sum << " " << j << " " << count << endl;
//         }
//         return count;
    }
};