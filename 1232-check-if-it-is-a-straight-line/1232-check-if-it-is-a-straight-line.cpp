class Solution {
public:
    double slope(double x1, double y1, double x2, double y2) {
        return (y2 - y1)/(x2 - x1);
    }

    bool checkStraightLine(vector<vector<int>>& coordinates) {
        sort(coordinates.begin(), coordinates.end());
        double prev_slope = slope(coordinates[0][0], coordinates[0][1], coordinates[1][0], coordinates[1][1]);
        int n = coordinates.size();
        
        for(int i = 2; i < n; i++) {
            double cur_slope = slope(coordinates[i-1][0], coordinates[i-1][1], coordinates[i][0], coordinates[i][1]);
            if(cur_slope != prev_slope) return false;
        }
        return true;
    }
};