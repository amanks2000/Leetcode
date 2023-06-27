class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, 
    int k) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> ans;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i = 0; i < n1; i++) {
            pq.push({nums1[i] + nums2[0], i, 0});
        }

        while(!pq.empty() && k--) {
            auto top = pq.top();
            pq.pop();
            int i = top[1], j = top[2];
            ans.push_back({nums1[i], nums2[j]});

            if(j + 1 < n2) pq.push({nums1[i] + nums2[j + 1], i, j + 1});
        }     
        return ans;   
    }
};