class Solution {
public:
    bool helper(vector<vector<char>>& board, string word, int i, int j) {
        if(word == "")
            return true;
        int m = board.size(), n = board[0].size();
        if(i >= m || j >= n || i < 0 || j < 0 || board[i][j] != word[0])
            return false;
        
        if(board[i][j] == word[0]) {
            board[i][j] = '0';
            bool left = helper(board, word.substr(1), i, j-1);
            bool right = helper(board, word.substr(1), i, j+1);
            bool top = helper(board, word.substr(1), i-1, j);
            bool down = helper(board, word.substr(1), i+1, j);
             board[i][j] = word[0];
            if(left || right || top || down)
                return true;
        }
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(helper(board, word, i, j))
                    return true;
            }
        }
        return false;
    }
};