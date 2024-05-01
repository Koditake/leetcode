impl Solution {
    pub fn climb_stairs(n: i32) -> i32 {
        if n < 3 {
            return n;
        }
        
        let (mut a, mut b, mut c) = (1, 2, 0); 
        for i in 2..n {
            //(c, a, b) = (a + b, b, c);
            c = a + b;
            a = b;
            b = c;
        }
        
        return c;
    }
}