class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int n = nums.size(), maxi = 0, mini = INT_MAX;
        priority_queue<int> pq;

        for(auto num: nums) {
            if(num % 2) num *= 2; // maximising all odd numbers

            pq.push(num);
            maxi = max(maxi, num);
            mini = min(mini, num);
        }

        int minDev = maxi - mini;

        while(pq.top() % 2 == 0) {
            int num = pq.top();
            pq.pop();
            pq.push(num/2);
            minDev = min(minDev, num - mini);
            mini = min(num/2, mini);
        }
        minDev = min(minDev, pq.top() - mini);
        return minDev;
    }
};