use std::cmp::Ordering::{Less,Greater};

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        if target < nums[0] || target > *nums.last().unwrap() { return -1; }
        if nums.len() == 1 {
            if target == nums[0] { return 0; }
            else { return -1 };
        }
        
        let (mut l, mut r) = (0, nums.len() as i32 - 1);
        
        while (l <= r) {
            let m = l + (r - l)/2;
            
            match nums[m as usize].cmp(&target) {
                Less => l = m + 1,
                Greater => r = m - 1,
                _ => return m,
            }
        }
        
        -1
    }
}