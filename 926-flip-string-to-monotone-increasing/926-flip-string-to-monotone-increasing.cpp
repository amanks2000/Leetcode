class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int flips = 0, countOne = 0;

        for(auto c: s) {
            if(c == '1') 
                ++countOne;
            else if(countOne > 0) {
                flips++; // 0 after a 1 suggests we need to flip a number
                --countOne; // after flipping 1 count decreases
            }
        }

        return flips;
    }
};