class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        int m = board.size(), n = board[0].size();
         for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                int sum = 0;
                if(j < n-1 && board[i][j+1] != 2){
                    sum += abs(board[i][j+1]);
                }
                
                if(i < m-1 && board[i+1][j] != 2){
                    sum += abs(board[i+1][j]);
                }
                
                if(j > 0 && board[i][j-1] != 2){
                    sum += abs(board[i][j-1]);
                }
                
                if(i > 0 && board[i-1][j] != 2){
                    sum += abs(board[i-1][j]);
                }
                
                if(i > 0 && j > 0 && board[i-1][j-1] != 2){
                    sum += abs(board[i-1][j-1]);
                }
                
                if(i < m-1 && j < n-1 && board[i+1][j+1] != 2){
                    sum += abs(board[i+1][j+1]);
                }
                
                if(i > 0 && j < n-1 && board[i-1][j+1] != 2){
                    sum += abs(board[i-1][j+1]);
                }
                
                if(i < m-1 && j > 0 && board[i+1][j-1] != 2){
                    sum += abs(board[i+1][j-1]);
                }
                cout << "  " << sum << " ";
                if(board[i][j]) {
                    if(sum != 2 && sum != 3)
                        board[i][j] = -board[i][j];                        
                }
                else {
                    if(sum == 3)
                        board[i][j] = 2;
                }
                cout << endl;
                // cout << sum << " ";
            }
             cout << endl;
        }
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(board[i][j] == 2)
                    board[i][j] = 1;
                else if(board[i][j] == -1)
                    board[i][j] = 0;
            }
        }
        
        
        
//         --> Solution using extra space, Space Complexity O(mn) <--
        
//         vector<vector<int>> ans(m, vector<int>(n, 0));
        
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(j < n-1)
//                     ans[i][j] += board[i][j+1];
//                 if(i < m-1)
//                     ans[i][j] += board[i+1][j];
//                 if(j > 0)
//                     ans[i][j] += board[i][j-1];
//                 if(i > 0)
//                     ans[i][j] += board[i-1][j];
//                 if(i > 0 && j > 0)
//                     ans[i][j] += board[i-1][j-1];
//                 if(i < m-1 && j < n-1)
//                     ans[i][j] += board[i+1][j+1];
//                 if(i > 0 && j < n-1)
//                     ans[i][j] += board[i-1][j+1];
//                 if(i < m-1 && j > 0)
//                     ans[i][j] += board[i+1][j-1];
//             }
//         }
//         for(int i = 0; i < m; i++) {
//             for(int j = 0; j < n; j++) {
//                 if(board[i][j]) {
//                     if(ans[i][j] == 2 || ans[i][j] == 3) board[i][j] = 1;
//                     else board[i][j] = 0;
//                 }
//                 else {
//                     if(ans[i][j] == 3) board[i][j] = 1;
//                 }
//             }
//         }
//         // for(int i = 0; i < m; i++) {
//         //     for(int j = 0; j < n; j++) {
//         //         cout << ans[i][j] << " ";       
//         //     }
//         //     cout << endl;
//         // }
        
    }
};