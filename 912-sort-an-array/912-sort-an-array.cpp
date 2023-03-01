class Solution {
public:
    vector<int> merge(vector<int>& arr1, vector<int>& arr2) {
        int i = 0, j = 0;
        int n1 = arr1.size(), n2 = arr2.size();
        vector<int> ans;

        while(i < n1 && j < n2) {
            if(arr1[i] < arr2[j]) {
                ans.push_back(arr1[i]);
                i++;
            }
            else {
                ans.push_back(arr2[j]);
                j++;
            }
        }
        while(i < n1) {
            ans.push_back(arr1[i]);
            i++;
        }
        while(j < n2) {
            ans.push_back(arr2[j]);
            j++;
        }
        return ans;
    }

    vector<int> sortArray(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) 
            return nums;
        vector<int> arr1, arr2;

        for(int i = 0; i < n/2; i++) arr1.push_back(nums[i]);
        for(int i = n/2; i < n; i++) arr2.push_back(nums[i]);

        arr1 = sortArray(arr1);
        arr2 = sortArray(arr2);

        vector<int> ans = merge(arr1, arr2);
        return ans;
    }
};