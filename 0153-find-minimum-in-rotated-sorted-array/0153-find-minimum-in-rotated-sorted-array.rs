use std::cmp::Ordering;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, nums.len() - 1);
        
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
        
        // array not rotated
        if nums[l] <= nums[r] {
            return nums[l];
        }
        
        while l < r && nums[l] > nums[r] {
            let m = l + (r - l)/2;
            match nums[m].cmp(&nums[l]) {
                Ordering::Less => r = m,
                _ => l = m + 1,
            }
        }
        
        return nums[l];
    }
}