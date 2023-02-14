class Solution {
public:
    string addBinary(string a, string b) {
        int n1 = a.size(), n2 = b.size();
        string ans = "";

        if(n1 < n2) addZero(a, n2 - n1);
        else if(n2 < n1) addZero(b, n1- n2);

        int rem = 0;
        for(int i = max(n1, n2) - 1; i >= 0; i--) {
            if(a[i] == '1' && b[i] == '1') {
                if(rem) ans += '1';
                else ans += '0';
                rem = 1;
            }
            else if(a[i] == '1' || b[i] == '1'){
                if(rem) ans += '0';
                else ans += '1';
            }
            else {
                if(rem) ans += '1';
                else ans += '0';
                rem = 0;
            }
        }

        if(rem) ans += '1';
        reverse(ans.begin(), ans.end());
        return ans;
    }

    void addZero(string& s, int n) {
        while(n--) {
            s = '0' + s;
        }
    }
};