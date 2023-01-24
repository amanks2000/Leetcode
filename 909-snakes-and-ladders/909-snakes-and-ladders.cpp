class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n = board[0].size(), target = pow(n, 2);
        vector<int> vis(target + 1, 0);
        reverse(board.begin(), board.end());

        for(int i = 0; i < n; i++) {
            if(i % 2) reverse(board[i].begin(), board[i].end());
        }

        queue<int> q;
        int res = 0;
        q.push(1);

        while(!q.empty()) {
            res++;
            int size = q.size();

            for(int k = 0; k < size; k++) {
                int pos = q.front();
                q.pop();

                for(int i = 1; i <= 6; i++) {
                    int nextPos = pos + i;
                    if(nextPos > target) continue;

                    int row = (nextPos - 1)/n, col = ((nextPos - 1) % n);
                    if(board[row][col] != -1 && board[row][col] != nextPos)
                        nextPos = board[row][col];

                    if(vis[nextPos]) continue;

                    if(nextPos == target) return res;
                    vis[nextPos] = 1;
                    q.push(nextPos);
                }
            }
        }

        return -1;
    }
};