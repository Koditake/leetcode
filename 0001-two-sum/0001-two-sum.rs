use std::collections::HashMap;

impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        let mut hash_map: HashMap<i32, i32> = HashMap::new();
        for i in 0..nums.len() {
            let left_over = target - nums[i];
            let data = hash_map.get_key_value(&left_over);
            if data.is_some() {
                return vec![i as i32, *(data.unwrap().1)]
            }
            hash_map.insert(nums[i], i as i32);
        }
        vec![]
    }
}