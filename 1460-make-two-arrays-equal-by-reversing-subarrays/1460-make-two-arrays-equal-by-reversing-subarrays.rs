use std::cmp::Ordering::{Equal};
impl Solution {
    pub fn can_be_equal(target: Vec<i32>, arr: Vec<i32>) -> bool {
        let mut vec1 = target.clone();
        vec1.sort();
        let mut vec2 = arr.clone();
        vec2.sort();
        
        return vec1 == vec2;
    }
}