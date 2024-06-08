use std::cmp::Ordering;

impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let (mut l, mut r) = (0, nums.len() - 1);
        
        
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