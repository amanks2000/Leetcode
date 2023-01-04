class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        int n = tasks.size(), cnt = 0;
        unordered_map<int, int> mp;
        for(auto it: tasks) mp[it]++;

        for(auto &[_, f]: mp) {
            int c3 = 0, c2 = 0;
            if(f == 1) return -1;

            if(f % 3 == 1) {
                c3 = f/3 - 1;
                c2 = 2;
            }
            else if(f % 3 == 2) {
                c3 = f/3;
                c2 = 1;
            }
            else c3 = f/3;

            cnt += c3 + c2;
        }

        return cnt;
    }
};