func climbStairs(n int) int {
    if n < 3 {
        return n;
    }

    var dp [3]int;
    dp[0] = 1;
    dp[1] = 2;
    for i := 2; i < n; i++ {
        dp[i%3] = dp[(i - 1)%3] + dp[(i - 2)%3];
    }

    return dp[(n - 1)%3];
}