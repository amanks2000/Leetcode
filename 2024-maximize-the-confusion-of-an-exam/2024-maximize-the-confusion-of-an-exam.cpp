class Solution {
public:
    int maxConsecutiveAnswers(string ansKey, int k) {
        int t_count = 0, f_count = 0, n = ansKey.size(), i = 0, j = 0;
        int res = 0;

        while(j < n) {
            if(ansKey[j] == 'T') t_count++;
            else f_count++;

            if(t_count <= k || f_count <= k) 
                res = max(res, j - i + 1);
            else {
                while(i <= j && t_count > k && f_count > k) {
                    if(ansKey[i] == 'T') t_count--;
                    else f_count--;
                    i++;
                }
            }
            j++;
        }
        return res;
    }
};