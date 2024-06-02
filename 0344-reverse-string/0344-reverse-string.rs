use std::mem;

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let (mut left, mut right) = (0, s.len() - 1);
        let mut swap;
        while left < right {
            swap = s[left];
            s[left] = s[right];
            s[right] = swap;
            left += 1;
            right -= 1;
        }    
    }
}