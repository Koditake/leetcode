use std::mem;

impl Solution {
    pub fn reverse_string(s: &mut Vec<char>) {
        let n = s.len();
        
        for l in 0..n/2 {
            s.swap(l, n - l - 1);
        }
    }
}