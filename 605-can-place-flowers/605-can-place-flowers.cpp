class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int cnt = 0, res = 0, flag = 0;
        for(int i = 0; i < flowerbed.size(); i++) {
            if(flowerbed[i] == 0) 
                cnt++;
            else {
                if(flag) res += (cnt - 1)/2;
                else res += cnt/2;
                flag = 1;
                cnt = 0;
            }
        }
        if(flag == 0) res += 1 + (cnt - 1)/2;
        else if(cnt > 1) res += cnt/2;
        return res >= n;
    }
};