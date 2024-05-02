impl Solution {
    pub fn find_max_k(nums: Vec<i32>) -> i32 {
        let mut nnums = nums.clone();
        let n = nums.len();
        
        if n < 2 {
            return -1; 
        }
        
        nnums.sort();
        
        if nnums[0] > 0 {
            return -1;
        }
        
        let (mut left, mut right) = (0, n - 1);
        
        while left < right {
            let sum = nnums[left as usize] + nnums[right as usize];
            if sum == 0 {
                return nnums[right as usize];
            } else if sum > 0 {
                right -= 1;
            } else {
                left += 1;
            }
        }
        
        -1
    }
}