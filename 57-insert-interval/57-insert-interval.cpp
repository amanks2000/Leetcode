class Solution {
public:
    bool isOverlapping(vector<int>& cur, vector<int>& next) {
        return min(cur[1], next[1]) - max(cur[0], next[0]) >= 0;
    }

    vector<int> mergeInterval(vector<int>& cur, vector<int>& next) {
        return {min(cur[0], next[0]), max(cur[1], next[1])};
    }

    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int n = intervals.size();
        vector<vector<int>> ans;
        
        // inserting newIntervals into intervals acc. to starti
        int flag = 0;
        for(int i = 0; i < n; i++) {
            if(intervals[i][0] > newInterval[0]) {
                intervals.insert(intervals.begin() + i, newInterval);
                flag = 1;
                break;
            }
        }
        if(!flag) {
            intervals.push_back(newInterval);
        }
        n++;

        // merge intervals
        for(int i = 0; i < n; i++) {
            auto cur = intervals[i];

            while(i < n && isOverlapping(cur, intervals[i])) {
                // intervals overlap
                cur = mergeInterval(cur, intervals[i]);
                i++;
            }

            i--;
            ans.push_back(cur);
        }
        return ans;
    }
};