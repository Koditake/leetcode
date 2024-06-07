class Solution {
public:
    int findMin(vector<int>& nums) {
        /*
            PLAN:
            -> Compare first and last
                -> if First is NOT larger than last -> array is not tampered => return first
                -> if First is larger than Last -> array is tampered => Apply solution

            => SOLUTION using binary search:
                -> find mid, compared with last
                    -> mid is NOT smaller than last -> pivot is between mid and last
                        => contract first to mid + 1, apply binary search
                    -> mid is smaller than last -> pivot is between first and mid
                        => contract last to mid, apply binary search.
        */

        int l = 0,
            r = nums.size() - 1;
        if (nums[l] <= nums[r]) {
            return nums[l];
        }
    
        while (l < r && nums[l] > nums[r]) {
            int m = l + (r - l)/2;

            if (nums[m] >= nums[l]) {
                l = m + 1;
            }
            else {
                r = m;
            }
        }

        return nums[l];
    }
};