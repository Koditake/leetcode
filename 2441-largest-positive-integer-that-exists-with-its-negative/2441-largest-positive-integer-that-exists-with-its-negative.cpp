class Solution {
public:
    int findMaxK(vector<int>& nums) {
        if (nums.size() < 2) {
            /// length == 1 -> not possible
            return -1;
        }
        sort(nums.begin(), nums.end());
        
        if (nums[0] > 0) {
            /// nums[0] after sort is > 0 -> no {-k,k} set possible
            return -1;
        }
        
        int l = 0, r = nums.size() - 1;
        while (l < r) {
            if (nums[l] + nums[r] == 0) {
                return nums[r];
            } else if (nums[l] + nums[r] > 0) {
                r--;
            } else {
                /// sum < 0 
                l++;
            }
        }
        
        return -1;
    }
};