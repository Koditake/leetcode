use std::cmp::Reverse;

impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        let n = names.len();
        
        // Create a vector of tuples (height, name)
        let mut map: Vec<(i32, String)> = Vec::with_capacity(n);
        
        // Populate the map with (height, name) pairs
        for i in 0..n {
            map.push((heights[i], names[i].clone())); // Use clone() to avoid moving names[i]
        }
        
        // Sort the map by height in descending order
        map.sort_by_key(|&(height, _)| Reverse(height));
        
        // Extract names into result vector
        let res: Vec<String> = map.iter().map(|(_, name)| name.clone()).collect();

        // Return the result vector
        res
    }
}