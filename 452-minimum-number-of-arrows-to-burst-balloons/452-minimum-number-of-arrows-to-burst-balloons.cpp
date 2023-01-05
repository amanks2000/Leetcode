#define pii pair<int, int>

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        
        // sorting with respect to end point
        for(auto &v: points)
            pq.push({v[1], v[0]});

        int arrow = 0, end;

        // if start point of current balloon is smaller than endpoint of prev balloon they can be
        // burst using one arrow otherwise increase arrow
        while(!pq.empty()) {
            if(arrow == 0 || pq.top().second > end){
                arrow++;
                end = pq.top().first;
            }
            pq.pop();
        }
        return arrow;
    }
};