impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut lower_case = vec![0;26];
        let mut upper_case = vec![0;26];
        
        for c in s.chars() {
            if c.is_uppercase() {
                upper_case[(c as u8 - 'A' as u8) as usize] += 1;
            } else {
                lower_case[(c as u8 - 'a' as u8) as usize] += 1;
            }
        }
        
        let mut res = 0; let mut is_center = 0;
        
        for i in 0..26 {
            if is_center == 0 && (lower_case[i]%2 == 1 || upper_case[i]%2 == 1) {
                is_center = 1;
            }
            res += (lower_case[i]/2)*2;
            res += (upper_case[i]/2)*2;
        }
        
        res + is_center as i32
    }
}