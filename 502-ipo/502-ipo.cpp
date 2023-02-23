#define pii pair<int, int>

class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue <int> available;
        priority_queue <pii, vector<pii>, greater<pii> > pq;

        int n = profits.size();
        for(int i = 0; i < n; i++) {
            pq.push({capital[i], profits[i]});
        }

        while(k > 0 && !pq.empty()) {
            int minCapital = pq.top().first;

            while(!pq.empty() && pq.top().first <= w) {
                int profit = pq.top().second;
                available.push(profit);
                pq.pop();
            }

            if(available.empty()) 
                return w;
            w += available.top();
            available.pop();
            k--;
        }

        if(pq.empty()) {
            while(!available.empty() && k > 0) {
                w += available.top();
                available.pop();
                k--;
            }
            return w;
        }
        return w;
    }
};