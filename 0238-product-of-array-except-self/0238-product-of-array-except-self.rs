impl Solution {
    pub fn product_except_self(nums: Vec<i32>) -> Vec<i32> {
        let mut right_left: Vec<i32> = vec![1; nums.len()];
        let mut prev_n: i32 = 1;

        for i in (0..nums.len()-1).rev() {
            right_left[i] = nums[i+1] * right_left[i+1];
        }

        for i in 0..nums.len() {
            right_left[i] = right_left[i] * prev_n;
            prev_n *= nums[i];    
        }

        return right_left;
    }
}