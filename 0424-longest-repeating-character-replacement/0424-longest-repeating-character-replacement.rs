use std::cmp::max;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let (s, k, A) = (s.as_bytes(), k as usize, 'A' as u8);
        let (mut l, mut w_l, mut w_c, mut veca) = (0, 0, 0, vec![0;26]);
        
        for r in 0..s.len() {
            let in_r = (s[r] - A) as usize;
            let in_l = (s[l] - A) as usize;
            veca[in_r] += 1;
            w_c = max(w_c, veca[in_r]);
            if r - l + 1 - w_c > k {
                veca[in_l] -= 1;
                l += 1;
            }
            w_l = max(w_l, r - l + 1);
        }
        
        w_l as i32
    }
}