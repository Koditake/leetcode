use std::cmp::Ordering::{Equal, Less, Greater};

impl Solution {
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let mut l = 0 as i32;
        let mut r = nums.len() as i32 - 1;
        
        while l <= r {
            let m = l + (r - l)/2;
            let mid = nums[m as usize];
            
            match mid.cmp(&target) {
                Less => l = m + 1,
                Equal => return m,
                Greater => r = m - 1
            }
        }
        
        -1
    }
}