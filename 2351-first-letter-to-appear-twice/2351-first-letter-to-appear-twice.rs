impl Solution {
    pub fn repeated_character(s: String) -> char {
        let mut sset = vec![0;26];
        
        for c in s.chars() {
            if sset[c as usize - 97] > 0 {
                return c;
            } else {
                sset[c as usize - 97] += 1;
            }
        }
        
        ' '
    }
}