class Solution {
public:
    int minFlips(int a, int b, int c) {
        int res = 0;

        for(int i = 31; i >= 0; i--) {
            int abit = (a >> i) & 1, bbit = (b >> i) & 1, cbit = (c >> i) & 1;
            
            if(cbit == 1 && abit == 0 && bbit == 0)
                res += 1;
            else if(cbit == 0) {
                if(abit == 1) res += 1;
                if(bbit == 1) res += 1;
            }
        }
        return res;
    }
};