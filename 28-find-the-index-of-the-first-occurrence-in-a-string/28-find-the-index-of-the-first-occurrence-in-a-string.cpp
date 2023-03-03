class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.size(), m = needle.size(), i = 0;
        string temp = "";

        while(i <= n - m) {
            temp = haystack.substr(i, m);
            if(temp == needle)
                return i;
            i++;
        }
        return -1;
    }
};