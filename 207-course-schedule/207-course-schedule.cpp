class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        vector<int> ind(numCourses, 0);    
        for(auto p: prerequisites) {
            adj[p[1]].push_back(p[0]);
            ind[p[0]]++;
        }
        // Detect if the graph is acyclic or not using Topo sort
        queue<int> q;
        vector<int> topo;
        for(int i = 0; i < numCourses; i++) {
            if(ind[i] == 0) q.push(i);
        }
        while(!q.empty()) {
            int top = q.front();
            q.pop();
            topo.push_back(top);
            for(auto i: adj[top]) {
                ind[i]--;
                if(ind[i] == 0) q.push(i);
            }
        }
        if(topo.size() == numCourses) return true;
        else return false;
    }
};