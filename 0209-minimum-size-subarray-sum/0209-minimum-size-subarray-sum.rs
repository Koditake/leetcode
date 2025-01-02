use std::cmp::min;

impl Solution {
    pub fn min_sub_array_len(target: i32, nums: Vec<i32>) -> i32 {
        let mut l:usize = 0;
        let (mut sum, mut res) = (0, i32::MAX);

        for r in 0..nums.len() {
            sum += nums[r];
            while sum >= target {
                l += 1;
                sum -= nums[l];
                res = min(res, (r - l + 1) as i32);    
            }
        }

        if res == i32::MAX {
            0
        } else {
            res
        }
    }
}