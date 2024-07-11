use std::cmp::Ordering::Greater;
impl Solution {
    pub fn next_greatest_letter(letters: Vec<char>, target: char) -> char {
        let mut l = 0 as i32;
        let mut r = letters.len() as i32 - 1;
        
        while l <= r {
            let m = l + (r - l)/2;
            let m_size = m as usize;
            
            match (letters[m_size] as u8).cmp(&(target as u8)) {
                Greater => r = m - 1,
                _ => l = m + 1
            }
        }
        
        letters[(l % (letters.len() as i32)) as usize]
    }
}