impl Solution {
    pub fn subset_xor_sum(nums: Vec<i32>) -> i32 {
        let n  = nums.len();
        
        if n == 0 {
            return 0;
        }
        
        let mut res = 0;

        for comb in 1..1 << n {
            let mut val_xor = 0;
            for i in 0..n {
                let mask = 1 << i;
                if comb & mask != 0 {
                    val_xor ^= nums[i as usize];
                }
            }
            res += val_xor;
        }
        res
    }
}