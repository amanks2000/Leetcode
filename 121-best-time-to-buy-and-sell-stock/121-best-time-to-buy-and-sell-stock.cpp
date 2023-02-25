class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int profit = 0, maxE = prices[n-1], maxP = INT_MIN;
        
        for(int i = n-2; i >= 0; i--) {
            if(prices[i] > maxE)
                maxE = prices[i];
            else {
                profit = maxE - prices[i];
                maxP = max(maxP, profit);
            }
        }
        if(maxP > 0)
            return maxP;
        return 0;
    }
};