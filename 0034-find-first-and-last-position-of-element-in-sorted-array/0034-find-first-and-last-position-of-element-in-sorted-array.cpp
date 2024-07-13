class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if (nums.size() < 1) {
            return {-1, -1};
        }
        
        int l = 0,
            r = nums.size() - 1;
        
        std::vector<int> res = {-1, -1};
        
        while (l <= r) {
            int m = l + (r - l)/2,
                mid = nums[m];
            
            if (mid < target) {
                l = m + 1;
            } else if (mid > target) {
                r = m - 1;
            } else {
                l = m, r = m;
                break;
            }
        }
        
        // Check if target was found
        if (l <= r && nums[l] == target) {
            // Expand l to find the first occurrence of target
            while (l >= 0 && nums[l] == target) {
                res[0] = l;
                l--;
            }

            // Expand r to find the last occurrence of target
            while (r < nums.size() && nums[r] == target) {
                res[1] = r;
                r++;
            }
        }

        return res;
    }
};