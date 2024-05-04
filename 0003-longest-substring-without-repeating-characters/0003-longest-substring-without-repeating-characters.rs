use std::collections::HashSet;

impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let n = s.len();
        let char_arr:Vec<char> = s.chars().collect();
        let mut charset = HashSet::new();
        let mut l = 0;
        let mut res:i32 = 0;

        for r in 0..n {
          if !charset.contains(&char_arr[r]) { // Use contains to check for existence
            res = std::cmp::max(res, (r - l + 1) as i32);
          } else {
            while charset.contains(&char_arr[r]) {
              charset.remove(&char_arr[l]);
              l += 1;
            }
          }
          charset.insert(&char_arr[r]);
        }

        res
    }
}