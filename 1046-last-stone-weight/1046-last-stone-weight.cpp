class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto it: stones) pq.push(it);

        while(1) {
            if(pq.size() == 1) return pq.top();
            if(pq.size() == 0) return 0;

            int n1 = pq.top();
            pq.pop();
            int n2 = pq.top();
            pq.pop();
            if(n1 > n2) pq.push(n1 - n2);
        }
        return 0;
    }
};