class Solution {
public:
    bool detectCycle(int i,vector<int>& vis,vector<int>& pathVis,vector<vector<int>>& graph, 
    set<int>& s) {
        vis[i] = 1;
        pathVis[i] = 1;
        for(auto it: graph[i]) {
            if(!vis[it]) {
                bool ans = detectCycle(it, vis, pathVis, graph, s);
                if(ans) return ans;
            }
            else {
                if(pathVis[it]) return true;
            }
        }
        pathVis[i] = 0;
        s.insert(i);
        return false;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        // If cycle doesn't exit from a node that node is a safe node
        // Since safe node ends at a terminal node there is no cycle
        // In other cases there will be a cycle in any of the paths
        // If any node is in path of a cycle, is not safe node
        int n = graph.size();
        vector<int> vis(n, 0);
        vector<int> pathVis(n, 0);
        vector<int> ans;
        set<int> s;
        for(int i = 0; i < n; i++) {
            if(!vis[i]) {
                if(!detectCycle(i, vis, pathVis, graph, s))
                    ans.push_back(i);
            }
        }
        for(auto it: ans) 
            s.insert(it);
        vector<int> v;
        for(auto i: s)
            v.push_back(i);
        return v;
    }
};