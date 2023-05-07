class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
        vector<int> nums, ans;
        int n = obstacles.size();

        for(auto &it: obstacles) {
            int pos = upper_bound(nums.begin(), nums.end(), it) - nums.begin();
            if(pos == nums.size())
                nums.push_back(it);

            nums[pos] = it;
            ans.push_back(pos + 1);
        }
        return ans;
    }
};