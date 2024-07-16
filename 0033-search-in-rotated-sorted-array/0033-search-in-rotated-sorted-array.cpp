class Solution {
public:
    auto binary_search(std::vector<int> &nums, int target, int l, int r) -> int {
        while (l < r) {
            int m = l + (r - l) / 2;
            
            if (nums[m] > target)
                r = m;
            else if (nums[m] < target)
                l = m + 1;
            else
                return m;
        }
        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        if (!nums.size())
            return -1;
        
        int l = 0,
            r = nums.size() - 1;
        
        if (nums[l] == target || nums[r] == target) {
            return (nums[l] == target)? l:r;
        }
        
        //not rotated
        if (nums[l] <= nums[r]) {
            return binary_search(nums, target, l, r);
        }

        // rotated -> *nums.begin() > *nums.end()
        while (l < r) {
            int m = l + (r - l)/2,
                mid = nums[m];
            
            if (mid < nums.back())
                r = m;
            else
                l = m + 1;
        }
        
        return nums[0] > target ? binary_search(nums, target, l, nums.size() - 1):binary_search(nums, target, 0, l);
    }
};