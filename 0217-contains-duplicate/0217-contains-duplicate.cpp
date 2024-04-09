class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n = nums.size(), flag = 0;
            std::sort(nums.begin(),nums.end());
            for (int i = 0;i < n-1; i++)
            {
                if (nums[i] == nums[i + 1]) {
                    flag = 1;
                    break;    
                }
            }
        return flag;
    }
};