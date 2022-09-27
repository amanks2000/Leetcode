class Solution {
public:
    string pushDominoes(string dominoes) {
        int n = dominoes.size();
        string left = dominoes, right = dominoes;
        // Get left string
        for(int i = n-2; i >= 0; i--) {
            if(left[i+1]=='L' && left[i] == '.')
                left[i] = 'L';
        }
        // Get right string
        for(int i = 0; i < n-1; i++) {
            if(right[i] == 'R' && right[i+1] == '.')
                right[i+1] = 'R';
        }
        
        int i = 0;
        while(i < n) {
            // cout << i << " " << dominoes[i] << " " << left[i] << " " << right[i] << endl;
            if(dominoes[i] == '.') {
                if(left[i] == '.' || right[i] == '.') {
                    if(left[i] == '.')
                        dominoes[i] = right[i];
                    else
                        dominoes[i] = left[i];
                    i++;
                }
                else {
                    if(left[i] != right[i]) {
                        int lo = i-1, count = 0;
                        // cout << "i: " << i << endl;
                        while(true) {
                            if(dominoes[i++] == '.') count++;
                            else break;
                        }
                        // cout << "i: " << i << endl;
                        i--;
                        int hi = i;
                        lo++; hi--;
                        while(lo < hi) {
                            dominoes[lo] = dominoes[lo-1];
                            dominoes[hi] = dominoes[hi+1];
                            lo++; hi--;
                        }
                        if(lo == hi)
                            dominoes[lo] = '.';
                    }
                }
            }
            else
                i++;
        }
        return dominoes;
    }
};