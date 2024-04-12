use std::cmp::Ordering;

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let n = height.len();
        
        if n < 2 {
            /// insufficient length for height vector
            return 0;
        }
        
        let (mut left, mut right, mut volMax) = (0, height.len() - 1, 0);
        
        while left < right {
            let vol = height[left].min(height[right]) * ((right - left) as i32);
            volMax = volMax.max(vol);
            
            if height[left] > height[right] {
                right -= 1;
            } else {
                left += 1;
            }
        }
        
        volMax
    }
}