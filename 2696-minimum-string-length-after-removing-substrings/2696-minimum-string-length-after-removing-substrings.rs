impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut varr:Vec<char> = Vec::new();
        for c in s.chars() {
            if !varr.is_empty() && ((c == 'B' && *varr.last().expect("WHY?") == 'A') || (c == 'D' && *varr.last().expect("WHY?") == 'C')) {
                varr.pop();
                continue;
            }
            varr.push(c);
        }
        
        return varr.len() as i32;
    }
}