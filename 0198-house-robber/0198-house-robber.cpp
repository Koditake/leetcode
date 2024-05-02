class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();

        if (n < 3) {
            return (n == 1)? nums[0]:std::max(nums[0], nums[1]);
        }
        
        int dp[3] = {0};
        dp[0] = nums[0];
        dp[1] = std::max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i % 3] = std::max(dp[(i - 1) % 3], dp[(i - 2) % 3] + nums[i]);
        }

        return dp[(n - 1) % 3];
    }
};