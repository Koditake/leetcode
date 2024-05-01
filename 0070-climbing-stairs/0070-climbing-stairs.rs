use std::vec::Vec;

impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n < 3 {
            return n;
        }

        let mut dp = vec![0;3];
        dp[0] = 1;
        dp[1] = 2;
        for i in 2..n {
            dp[(i%3) as usize] = dp[((i - 1)%3) as usize] + dp[((i - 2)%3) as usize];
        }

        return dp[((n - 1)%3) as usize];
    }
}