class Solution {
public:
    string convert(string s, int numRows) {
        string ans = "";
        int n = s.size();

        if(n == 1 || numRows == 1)
            return s;
        
        int w = (n % 2 == 0) ? n/2 : n/2+1;
        // cout << w << endl;
        char pattern[numRows][w];
        memset(pattern, '-', sizeof(pattern));
        
        int i = 0, j = 0, k = 0, count = 0;
        while(k < n) 
        {
            if(count % 2 == 0) {
                while(i < numRows && k < n) {
                    pattern[i][j] = s[k++];
                    i++;
                }
                k = (k == n) ? k : k-1;
                count++; i--;
            }

            if((count-1)%4 == 0) {
                while(j < w && i >= 0 && k < n) {
                    pattern[i][j] = s[k++];
                    i--;
                    j++;
                }
                k = (k == n) ? k : k-1;
                count++;
                i++; j--;
            }
            count++;            
        
        }
        
        for(int i = 0; i < numRows; i++) {
            for(int j = 0; j < w; j++) {
                if(pattern[i][j] != '-')
                    ans += pattern[i][j];
            }
        }
        
        // cout << ans << endl;
        return ans;
    }
};