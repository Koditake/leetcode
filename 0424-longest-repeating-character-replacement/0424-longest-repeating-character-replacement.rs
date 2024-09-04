impl Solution {
    pub fn character_replacement(s: String, k: i32) -> i32 {
        let mut l:usize = 0;
        let (mut cmax, mut res) = (0,0);
        let mut cmap = vec![0;26];
        let charr:Vec<char> = s.chars().collect();
        
        for r in 0..charr.len() {
            let chr = (charr[r] as u8 - 'A' as u8) as usize;
            
            cmap[chr] += 1;
            cmax = if cmax < cmap[chr] {cmap[chr]} else {cmax};
            while (r - l + 1) as i32 - cmax > k {
                cmap[(charr[l] as u8 - 'A' as u8) as usize] -= 1;
                l += 1;
            }
            res = if ((r - l + 1) as i32 > res) {(r - l + 1) as i32} else {res};
        }
        
        res
    }
}