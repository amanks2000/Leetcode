class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int sum = 0, cnt = 0;

        for(auto it: costs) {
            sum += it;
            if(sum > coins) 
                return cnt;
            cnt++;
        }
        return cnt;
    }
};