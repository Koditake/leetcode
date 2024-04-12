impl Solution {
    pub fn three_sum(numbers: Vec<i32>) -> Vec<Vec<i32>> {
        let mut nums = numbers.clone();
        let mut res = Vec::new();
        
        /// sort the input array
        nums.sort();

        
        for i in 0..nums.len() {
            // From now on only > 0 can be found, so no need to iterate further
            if nums[i] > 0 {
                return res;
            }
            
            //skip all identical entries to avoid duplicate answers
            if i > 0 && nums[i] == nums[i - 1] {
                continue;
            }

            
            let mut left = i + 1;
            let mut right = nums.len() - 1;

            while left < right {
                let sum = nums[i] + nums[left] + nums[right];
                if sum > 0 {
                    right -= 1;
                } else if sum < 0 {
                    left += 1
                } else {
                    res.push(vec![nums[i], nums[left], nums[right]]);
                    left += 1;

                    while nums[left] == nums[left - 1] && left < right {
                        left += 1;
                    }
                }
            }
        }

        return res;
    }
}