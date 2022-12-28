class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        for(auto it: piles) pq.push(it);

        while(k--) {
            int top = pq.top();
            pq.pop();
            pq.push(top - top/2);
        }

        int res = 0;
        while(!pq.empty()) {
            res += pq.top();
            pq.pop();
        }

        return res;
    }
};