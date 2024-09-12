impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut res = 0;
        let mut cset = vec![false;26];
        
        for c in allowed.chars() {
            cset[(c as u8 - 'a' as u8) as usize] = true;
        }
        
        for word in words {
            let mut is_const = true;
            for c in word.chars() {
                if cset[(c as u8 - 'a' as u8) as usize] == false {
                    is_const = false;
                }
            }
            if is_const { res += 1; }
        }
        
        return res;
    }
}