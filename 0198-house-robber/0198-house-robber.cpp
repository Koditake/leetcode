class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        
        if (n < 3) {
            return (n == 1)? nums[0]:std::max(nums[0], nums[1]);
        }
        
        int loot0 = nums[0],
            loot1 = std::max(nums[0], nums[1]),
            lootn = 0;
        
        for (int i = 2; i < n; ++i) {
            lootn = std::max(loot1, loot0 + nums[i]);
            loot0 = loot1;
            loot1 = lootn;
        }
        
        return lootn;
    }
};