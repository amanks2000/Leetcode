class Solution {
public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<vector<int>> adj(n);
        vector<int> indegree(n, 0);

        for(auto &it: edges) {
            adj[it[0]].push_back(it[1]);
            indegree[it[1]]++;
        }

        vector<vector<int>> count(n, vector<int>(26, 0)); 
        // count stores max count of each color till that node
        queue<int> q;

        for(int i = 0; i < n; i++) {
            if(indegree[i] == 0) q.push(i);
        }

        int res = 0, nodes = 0;

        while(!q.empty()) {
            int top = q.front();
            q.pop();

            res = max(res, ++count[top][colors[top] - 'a']);   
            nodes++;

            for(auto &node: adj[top]) {
                for(int i = 0; i < 26; i++)
                    count[node][i] = max(count[node][i], count[top][i]);

                indegree[node]--;
                if(indegree[node] == 0) {
                    q.push(node);
                }
            }         
        }

        if(nodes < n) return -1;
        return res;
    }
};