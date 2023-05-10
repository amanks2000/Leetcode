class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int k = 0, num = 1;

        while(k <= n/2) {
            for(int j = k; j < n - k; j++)
                ans[k][j] = num++;

            if(num > n * n) break;

            for(int i = k + 1; i < n - k; i++) 
                ans[i][n-k-1] = num++;
            
            for(int j = n - k - 2; j >= k; j--) 
                ans[n-k-1][j] = num++;
            
            for(int i = n - k - 2; i > k; i--) 
                ans[i][k] = num++;
            
            k++;            
        }
        return ans;
    }
};