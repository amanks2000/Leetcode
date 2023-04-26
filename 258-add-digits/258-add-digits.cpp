class Solution {
public:
    int addDigits(int num) {
        if(num <= 9) return num;
        int size = log10(num) + 1;

        while(size > 1) {
            int temp = num;
            num = 0;
            while(temp > 0) {
                num += temp % 10;
                temp /= 10;
            }
            if(num <= 9) return num;
            size = log10(num) + 1;
        }
        return num;
    }
};