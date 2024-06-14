class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res = 0,
            need = 0;
        for (int num:nums) {
            res += std::max(need - num, 0);
            need = std::max(num, need) + 1;
        }
        
        return res;
    }
};