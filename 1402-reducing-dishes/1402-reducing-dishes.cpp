class Solution {
public:
    int maxSatisfaction(vector<int>& satisfaction) {
        int n = satisfaction.size();
        sort(satisfaction.begin(), satisfaction.end(), greater<int>());

        int res = 0, pos = -1;
        for(int i = 0; i < n; i++) {
            res += satisfaction[i];
            if(res > 0) pos = i;
            else break;
        }

        int cnt = 1;
        res = 0;
        for(int j = pos; j >= 0; j--) {
            res += satisfaction[j]*cnt;
            cnt++;
        }
        return res;
    }
};