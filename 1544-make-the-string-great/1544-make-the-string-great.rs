impl Solution {
    pub fn make_good(s: String) -> String {
        let mut ss = Vec::new();
        for c in s.bytes()
        {
            if !ss.is_empty() && ss.last().unwrap() ^ c == 32
            { 
                ss.pop();
            }
            else { ss.push(c); }
        }
        String::from_utf8(ss).unwrap()
    }
}