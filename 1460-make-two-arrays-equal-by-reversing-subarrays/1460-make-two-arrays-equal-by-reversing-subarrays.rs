use std::collections::HashMap;

impl Solution {
    pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
        let mut imap = HashMap::new();
        
        for i in 0..arr.len() {
            *imap.entry(target[i]).or_insert(0) += 1;
            *imap.entry(arr[i]).or_insert(0) -= 1;
        }
        
        for (num,freq) in imap {
            if freq != 0 {
                return false;
            }
        }
        
        true
    }
}