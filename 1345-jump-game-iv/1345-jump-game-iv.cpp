class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, vector<int>> mp;
        int n = arr.size();

        for(int i = 0; i < n; i++)
            mp[arr[i]].push_back(i);

        queue<int> q;
        q.push(0); // Push first index
        vector<int> vis(n, 0);
        int steps = 0;

        while(!q.empty()) {
            int sz = q.size();

            for(int i = 0; i < sz; i++) {
                int top = q.front();
                q.pop();
                if(top == n-1) return steps;

                vector<int>& vec = mp[arr[top]];
                vec.push_back(top - 1);
                vec.push_back(top + 1); // vec contains all possible movemnet of jump

                for(auto it: vec) {
                    if(it >= 0 && it < n && !vis[it]) {
                        q.push(it);
                        vis[it] = 1;
                    }
                }
                vec.clear(); // to not push the same elements again into queue
            }
            steps++;
        }
        return -1;
    }
};