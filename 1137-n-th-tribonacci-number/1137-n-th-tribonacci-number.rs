impl Solution {
    pub fn tribonacci(n: i32) -> i32 {
        if n == 0 {
            return 0;
        }
        
        if n < 3 {
            return 1;
        }
        
        let (mut t1, mut t2, mut t3, mut res) = (0, 1, 1, 2);
        
        for i in 2..n {
            res = t1 + t2 + t3;
            (t1, t2, t3) = (t2, t3, res);
        }
        
        res
    }
}