class Solution {
public:
    bool isVowel(char& s) {
        if(s == 'a' || s == 'e' || s == 'i' || s == 'o' || s == 'u')
            return true;
        return false;
    }

    int maxVowels(string s, int k) {
        int n = s.size(), j = 0, i = 0, cnt = 0, res = 0;

        while(j < n) {
            if(isVowel(s[j]))
                cnt++;

            if(j - i + 1 == k) {
                res = max(res, cnt);
                if(isVowel(s[i]))
                    cnt--;
                i++;
            }
            j++;
        }
        return res;
    }
};