impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut res = 0;
        
        for str in details {
            let age:i32 = str[11..13].parse::<i32>().unwrap();
            if age > 60 {
                res += 1;
            }
        }
        
        res
    }
}