use std::vec::Vec;

impl Solution {
    pub fn two_sum(numbers: Vec<i32>, target: i32) -> Vec<i32> {
        let mut index1 = 0;
        let mut index2 = numbers.len() - 1;
        while index1 < index2 {
            if numbers[index1] + numbers[index2] > target {
                index2 -= 1;
            } else if numbers[index1] + numbers[index2] == target {
                break;
            } else {
                index1 += 1;
            }
        }
        
        return vec![(index1 + 1) as i32, (index2 + 1) as i32];
    }
}