impl Solution {
    pub fn single_non_duplicate(nums: Vec<i32>) -> i32 {
        let mut l = 0;
        let mut r = nums.len() as i32 - 1;

        while l < r {
            let m = l + (r - l) / 2;
            let num = nums[m as usize];
            let num_cmp = if m % 2 == 0 { nums[(m + 1) as usize] } else { nums[(m - 1) as usize] };
            
            if num == num_cmp {
                l = m + 1;
            } else {
                r = m;
            }
        }

        nums[l as usize]
    }
}