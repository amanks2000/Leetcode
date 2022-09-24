class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        int m = matrix.size(), n = matrix[0].size();
        int c = 0;
        int tot = m*n;
        int i=0,j = 0;
        while(tot > 0) 
        {
            while(j < n-c-1 && tot) {
                ans.push_back(matrix[i][j]);
                tot--;
                j++;
            }
            while(i < m-c-1 && tot) {
                ans.push_back(matrix[i][j]);
                tot--;
                i++;
            }
            while(j > c && tot) {
                ans.push_back(matrix[i][j]);
                tot--;
                j--;
            }
            // cout << matrix[i][j] << " " << tot << endl;
            c++;
            while(i > c && tot) {
                ans.push_back(matrix[i][j]);
                tot--;
                i--;
            }
            if(tot == 1) {
                ans.push_back(matrix[i][j]);
                break;
            }
        }
        return ans;
    }
};