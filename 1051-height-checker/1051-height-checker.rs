impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut heights_sort = heights.clone();
        heights_sort.sort_unstable();
        heights
            .iter()
            .zip(heights_sort.iter())
            .filter(|(h, hs)| h != hs)
            .count() as i32
    }
}