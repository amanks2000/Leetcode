class Solution {
public:
    vector<int> addToArrayForm(vector<int>& num, int k) {
        int n = num.size();
        int ptr = n-1, carry = 0;

        while(ptr >= 0) {
            int last = k % 10;
            k /= 10;
            num[ptr] += last + carry;
            carry = num[ptr]/10;
            num[ptr] %= 10;
            ptr--;
        }

        while(k > 0) {
            int last = k % 10;
            k /= 10;
            int x = last + carry;
            carry = x/10;
            x %= 10;
            num.insert(num.begin(), x);
        }

        if(carry) num.insert(num.begin(), 1);
        return num;
    }
};