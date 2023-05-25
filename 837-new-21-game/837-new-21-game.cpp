class Solution {
public:
    double new21Game(int N, int K, int maxPts) {
        if (K == 0) return 1.0;
        if (N >= K-1 + maxPts) return 1.0;

        vector<double> dp(N + 1, 0);

        double probability = 0; 
        double windowSum = 1; 
        dp[0] = 1;
        for (int i = 1; i <= N; i++) {
            dp[i] = windowSum / maxPts;

            if(i < K) windowSum += dp[i];
            else probability += dp[i];
            
            if(i >= maxPts) windowSum -= dp[i - maxPts];
        }
        return probability;
    }
};