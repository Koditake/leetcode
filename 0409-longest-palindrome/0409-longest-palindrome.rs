use std::collections::HashMap;

impl Solution {
    pub fn longest_palindrome(s: String) -> i32 {
        let mut ch_map: HashMap<char, i32> = HashMap::new();
        let mut res = 0;
        let mut is_center = 0;

        for c in s.chars() {
            *ch_map.entry(c).or_insert(0) += 1;
        }

        for (_, &f) in ch_map.iter() {
            res += f / 2;
            if is_center == 0 && f % 2 == 1 {
                is_center = 1;
            }
        }

        res * 2 + is_center
    }
}