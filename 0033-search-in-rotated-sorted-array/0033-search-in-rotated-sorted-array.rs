use std::cmp::Ordering::{Less,Greater,Equal};

impl Solution {
    fn binary_search(nums: Vec<i32>, target: i32, mut l: i32, mut r: i32) -> i32 {
        while l < r {
            let m = l + (r - l)/2;
            
            match nums[m as usize].cmp(&target) {
                Less => l = m + 1,
                Greater => r = m,
                _ => return m,
            };
        }   
        
        -1
    }
    
    pub fn search(nums: Vec<i32>, target: i32) -> i32 {
        let n = nums.len();
        
        let (mut l, mut r) = (0, n as i32 - 1);
        
        //check if target is at edges
        if nums[0] == target {
            return l;
        }
        if nums[n - 1] == target {
            return r;
        }
        
        // check if array was not rotated
        if nums[0] <= nums[n - 1] {
            return Self::binary_search(nums,target,l,r);
        }
        
        // Array was rotate -> find rotated point
        while l < r {
            let m = l + (r - l)/2;
            
            match nums[m as usize].cmp(&nums[n - 1]) {
                Less => r = m,
                _ => l = m + 1,
            };
        }
        
        if (nums[0] <= target) {
            return Self::binary_search(nums, target, 0, l);
        } else {
            return Self::binary_search(nums, target, l, n as i32 - 1);
        }
        
        -1
    }
}