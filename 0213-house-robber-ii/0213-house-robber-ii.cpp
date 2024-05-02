class Solution {
public:
    int robHelp(vector<int> &nums, int start, int end) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        
        int dp1 = 0, dp2 = 0, dp3 = 0;
        
        for (int i = start; i <= end; ++i) {
            dp3 = std::max(dp1 + nums[i], dp2);
            dp1 = dp2;
            dp2 = dp3;
        }
        
        return dp3;
    }
    
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        return std::max(robHelp(nums,0, n - 2), robHelp(nums,1, n - 1));
    }
};