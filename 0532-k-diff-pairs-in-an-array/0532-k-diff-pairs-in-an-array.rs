use std::collections::HashMap;

impl Solution {
    pub fn find_pairs(nums: Vec<i32>, k: i32) -> i32 {
        if k < 0 || nums.is_empty() {
            return 0;
        }
        
        let mut int_map:HashMap<i32, i32> = HashMap::new();
        
        for i in nums {
            *int_map.entry(i).or_insert(0) += 1;
        }
        
        let mut res = 0;
        
        for (num,&freq) in int_map.iter() {
            if k == 0 {
                // count how many elements in the array that appear more than twice
                if freq >= 2 {
                    res += 1;
                }
            } else {
                if int_map.contains_key(&(num + k)) {
                    res += 1;
                }
            }
        }
        
        res
    }
}