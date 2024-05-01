class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        if (n <= 2) {
            return min(cost[0],cost[1]);
        }

        int dp[3];
        dp[0] = cost[0];
        dp[1] = cost[1];
        dp[2] = 0;

        for (size_t i = 2; i < n; i++) {
            dp[i % 3] = min(dp[(i - 1) % 3],dp[( i - 2) % 3]) + cost[i];
        }

        return min(dp[(n - 1) % 3], dp[(n - 2) % 3]);
    }
};