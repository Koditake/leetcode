impl Solution {
    pub fn search_insert(nums: Vec<i32>, target: i32) -> i32 {
        let mut begin = 0;
        let mut end = nums.len();
        while begin != end {
            let mut current = (begin + end)/2;
            if nums[current] == target {
                return current as i32;
            }
            if nums[current] < target {
                begin = current + 1;
            }
            else {
                end = current;
            }
        }
        begin as i32
    }
}