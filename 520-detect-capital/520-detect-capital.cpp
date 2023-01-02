class Solution {
public:
    int n;
    bool checkCapital(int ind, string& s, int flag) {
        for(int i = ind; i < n; i++) {
            if((isupper(s[i]) && flag) || (islower(s[i]) && !flag))
                continue;
            else return false; 
        }
        return true;
    }

    bool detectCapitalUse(string& s) {
        n = s.size();
        if(n == 1) return true;

        if(islower(s[0])) return checkCapital(1, s, 0);
        else if(isupper(s[0]) && islower(s[1])) return checkCapital(2, s, 0);
        else if(isupper(s[0])) return checkCapital(1, s, 1);

        return false;
    }
};