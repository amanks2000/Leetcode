class Solution {
public:
    int largestVariance(string s) {
        int res = 0;

        for(char c1 = 'a'; c1 <= 'z'; c1++) {
            for(char c2 = 'a'; c2 <= 'z'; c2++) {
                if(c1 == c2) continue;

                int c1_count = 0, c2_count = 0, flag = 0;
                for(auto it: s) {
                    if(it == c1) c1_count++;
                    if(it == c2) c2_count++;

                    if(c2_count > c1_count) {
                        c2_count = 0;
                        c1_count = 0;
                        flag = 1;
                    }
                    else if(c2_count == 0 && flag) {
                        res = max(res, c1_count - 1);
                    }
                    else if(c2_count > 0) {
                        res = max(res, c1_count - c2_count);
                    }
                }
            }
        }
        return res;
    }
};