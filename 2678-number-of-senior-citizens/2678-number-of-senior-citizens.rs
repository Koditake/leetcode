impl Solution {
    pub fn count_seniors(details: Vec<String>) -> i32 {
        let mut res = 0;
        
        for str in details {
            if str[11..13].parse::<i32>().unwrap() > 60 {
                res += 1;
            }
        }
        
        res
    }
}