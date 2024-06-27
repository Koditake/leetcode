use std::collections::HashMap;

impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        let mut starchart = HashMap::new();
        let mut res = vec![0, 0];
        
        for edge in edges {
            *starchart.entry(edge[0]).or_insert(0) += 1;
            *starchart.entry(edge[1]).or_insert(0) += 1;
            
            if starchart[&edge[0]] > res[1] {
                res[0] = edge[0];
                res[1] = *starchart.get(&edge[0]).unwrap();
            }
            
            if starchart[&edge[1]] > res[1] {
                res[0] = edge[1];
                res[1] = *starchart.get(&edge[1]).unwrap();
            }
        }
        
        res[0]
    }
}