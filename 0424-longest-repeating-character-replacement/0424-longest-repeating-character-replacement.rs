use std::cmp::max;

impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let charr:Vec<char> = s.chars().collect();
        let (mut l, mut w_l, mut w_c) = (0, 0, 0);
        let mut veca = vec![0;26];
        
        for r in 0..s.len() {
            let in_r = (charr[r] as u8 - 'A' as u8) as usize;
            let in_l = (charr[l] as u8 - 'A' as u8) as usize;
            veca[in_r] += 1;
            w_c = max(w_c, veca[in_r]);
            if r - l + 1 - w_c > k as usize {
                veca[in_l] -= 1;
                l += 1;
            }
            w_l = max(w_l, r - l + 1);
        }
        
        return w_l as i32;
    }
}