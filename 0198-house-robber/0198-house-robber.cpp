class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return (n == 1)? nums[0]:std::max(nums[0], nums[1]);
        }
        
        std::vector<int> loot(n + 1);
        loot[0] = nums[0];
        loot[1] = std::max(nums[0], nums[1]);
        
        for (int i = 2; i < n; ++i) {
            loot[i] = std::max(loot[i - 1], loot[i - 2] + nums[i]);
        }
        
        return loot[n - 1];
    }
};