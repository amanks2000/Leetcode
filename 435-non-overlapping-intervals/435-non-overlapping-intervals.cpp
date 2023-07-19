class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int n = intervals.size();
        auto prev = intervals[0];
        int res = 0;

        for(int i = 1; i < n; i++) {
            auto cur = intervals[i];
            if(cur[0] < prev[1]) {
                res++;
                if(cur[1] < prev[1])
                    prev = cur;
            }
            else prev = cur;
        }
        return res; 
    }
};