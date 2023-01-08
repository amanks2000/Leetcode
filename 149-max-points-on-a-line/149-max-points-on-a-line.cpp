class Solution {
public:
    float slope(vector<int>& p1, vector<int>& p2) {
        float a = p1[1] - p2[1], b = p1[0] - p2[0];
        if(b == 0) return INT_MAX;
        return a/b;
    }

    int maxPoints(vector<vector<int>>& points) {
        int n = points.size(), maxi = 0;

        for(int i = 0; i < n; i++) {
            unordered_map<float, int> mp;

            for(int j = 0; j < n; j++) {
                if(i == j) continue;
                float m = slope(points[i], points[j]);
                mp[m]++;
                maxi = max(mp[m], maxi);
            }
        }

        return maxi + 1;
    }   
};