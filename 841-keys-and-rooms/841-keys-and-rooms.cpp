class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        q.push(0);
        vector<int> vis(n, 0);

        while(!q.empty()) {
            int node = q.front();
            q.pop();
            vis[node] = 1;

            for(auto it: rooms[node]) {
                if(!vis[it])
                    q.push(it);
            }
        }

        for(auto it: vis) {
            if(it == 0) return false;
        }
        return true;
    }
};