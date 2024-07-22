use std::cmp::Reverse;

impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let n = names.len();
        
        // Create a vector of tuples (height, name)
        let mut map: Vec<(i32, String)> = heights.iter().zip(names.iter()).map(|(&height, name)| (height, name.clone())).collect();

        // Sort the map by height in descending order
        map.sort_by_key(|&(height, _)| Reverse(height));
        
        // Extract names into result vector
        let res: Vec<String> = map.iter().map(|(_, name)| name.clone()).collect();

        // Return the result vector
        res
    }
}