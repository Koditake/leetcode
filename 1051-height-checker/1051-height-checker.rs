impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut expected = heights.clone();
        expected.sort();
        let mut res = 0;
        for i in 0..heights.len() {
            if heights[i] != expected[i] {
                res += 1;
            }
        }
        
        res
    }
}