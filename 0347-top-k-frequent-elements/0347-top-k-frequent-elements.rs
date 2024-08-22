use std::collections::HashMap;

impl Solution {
    pub fn top_k_frequent(nums: Vec<i32>, k: i32) -> Vec<i32> {
        let n = nums.len();
        if n == k as usize { 
            return nums;
        }
        
        let mut nmap = HashMap::new();
        for num in nums {
            *nmap.entry(num).or_insert(0) += 1;
        }
        
        let mut buckets:Vec<Vec<i32>> = vec![Vec::new(); n + 1];
        for (num,freq) in nmap {
            buckets[freq].push(num);
        }
        
        let mut res = Vec::new();
        for i in (0..buckets.len()).rev() {
            if res.len() >= k as usize { break; }
            if !buckets[i].is_empty() {
                res.extend(buckets[i].iter().cloned());
            }
        }
        
        res
    }
}