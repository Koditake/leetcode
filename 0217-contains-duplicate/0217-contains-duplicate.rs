use std::collections::HashMap;

impl Solution {
    pub fn contains_duplicate(nums: Vec<i32>) -> bool {
        let mut hist = HashMap::new();
        
        for n in nums {
            if !hist.contains_key(&n) {
                hist.entry(n).and_modify(|n| *n += 1).or_insert(1);
            } else {
                return true;
            }
        }
        
        false
    }
}