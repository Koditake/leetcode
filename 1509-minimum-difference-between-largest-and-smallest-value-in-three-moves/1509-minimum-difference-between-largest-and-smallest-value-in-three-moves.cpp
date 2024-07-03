class Solution {
public:
    int minDifference(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        int n = nums.size();
        if(n <= 4){
            return 0;
        }
        
        //1st
        int res = nums[n - 1] - nums[3];
        //2nd
        res = std::min(res,nums[n - 4] - nums[0]);
        //3rd
        res = std::min(res,nums[n - 2] - nums[2]);
        //4th
        res = std::min(res,nums[n - 3] - nums[1]);
        
        return res;
    }
};