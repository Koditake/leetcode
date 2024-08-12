use std::collections::HashMap;
use std::cmp::max;
impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let charr:Vec<char> = s.chars().collect();
        let (mut l, mut w_l, mut w_c) = (0, 0, 0);
        let mut cmap = HashMap::new();
        
        for r in 0..s.len() {
            *cmap.entry(charr[r]).or_insert(0) += 1;
            w_c = max(w_c,*cmap.get(&charr[r]).unwrap());
            if (r - l + 1) - w_c > k as usize {
                cmap.entry(charr[l]).and_modify(|cnt| *cnt -= 1);
                l += 1;
            }
            
            w_l = max(w_l, r - l + 1);
        }
        return w_l as i32;
    }
}