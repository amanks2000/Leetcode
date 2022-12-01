class Solution {
public:
    bool isVowel(char c) {
        return c == 'a' || c == 'e'|| c == 'i' || c == 'o' || c == 'u' || 
        c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U';
    }

    int helper(string s, int st, int ed) {
        int cnt = 0;
        for(int i = st; i <= ed; i++) {
            if(isVowel(s[i])) {
                cnt++;
            }
        }
        return cnt;
    }

    bool halvesAreAlike(string s) {
        int n = s.size();
        int mid = (n - 1)/2;
        int x = helper(s, 0, mid);
        int y = helper(s, mid + 1, n - 1);
        return x == y;
    }
};