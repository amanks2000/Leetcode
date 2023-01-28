class SummaryRanges {
public:
    set<int> s;
    SummaryRanges() {
    }
    
    void addNum(int value) {
        s.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<vector<int>> ans;
        int start = -1, end = -1;

        for(auto num: s) {
            if(start == -1) {
                start = num;
                end = num;
            }
            else if(end == num - 1) {
                end = max(num, end);
            }
            else {
                ans.push_back({start, end});
                start = num, end = num;
            }
        }

        if(start != -1) ans.push_back({start, end});
        return ans;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges* obj = new SummaryRanges();
 * obj->addNum(value);
 * vector<vector<int>> param_2 = obj->getIntervals();
 */