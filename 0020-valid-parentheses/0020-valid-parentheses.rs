impl Solution {
    pub fn is_valid(s: String) -> bool {
        let mut cstk = Vec::new();
        let cstring:Vec<char> = s.chars().collect();
        for c in cstring {
            if !cstk.is_empty() &&
                    ((cstk.last().unwrap() == &'[' && c == ']') || 
                    (cstk.last().unwrap() == &'{' && c == '}') ||
                    (cstk.last().unwrap() == &'(' && c == ')')) {
                        cstk.pop();
                }  else {
                cstk.push(c);
            }
        }
        cstk.is_empty()
    }
}