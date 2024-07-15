class Solution {
public:
    int findMin(vector<int>& nums) {
        // Array was not rotated or have only one element.
        if (nums.front() <= nums.back()) return nums.front();
        
        int n = nums.size(),
            l = 0,
            r = n - 1;
        
        while (l < r) {
            int m = l + (r - l)/2,  
                mid = nums[m];
            
            if (mid < nums.back()) {
                r = m;
            } else {
                l = m + 1;
            }
        }
        
        return nums[l];
    }
};