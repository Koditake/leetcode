impl Solution {
    pub fn length_of_longest_substring(s: String) -> i32 {
        let u8_arr:Vec<char> = s.chars().collect();
        let mut res = 0;
        let mut l = 0;
        let mut u8_cnt = vec![0;256];
        for r in 0..u8_arr.len() {
            u8_cnt[u8_arr[r] as usize] += 1;
            while u8_cnt[u8_arr[r] as usize] > 1 {
                u8_cnt[u8_arr[l] as usize] -= 1;
                l += 1;
            }
            res = res.max(r - l + 1);
        }
        
        res as i32
    }
}