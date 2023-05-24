#define pii pair<int, int>
#define ll long long

class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pii> v12;
        int n = nums1.size();
        
        for(int i = 0; i < n; i++) 
            v12.push_back({nums2[i], nums1[i]});
        
        sort(v12.begin(), v12.end(), greater<pii>()); // sort w.r.t nums2
        
        for(int i = 0; i < n; i++) {
            nums2[i] = v12[i].first;
            nums1[i] = v12[i].second;
        }
        
        priority_queue <int, vector<int>, greater<int> > pq;
        ll sum = 0, ans = 0;
        
        for(int i = 0; i < n; i++) {
            sum += nums1[i];
            pq.push(nums1[i]);
            if(i >= k) {
                sum -= pq.top();
                pq.pop();
            }
            if(i >= k-1) {
                ans = max(ans, sum * nums2[i]);
            }
            
        }
        return ans;      
        
    }
};