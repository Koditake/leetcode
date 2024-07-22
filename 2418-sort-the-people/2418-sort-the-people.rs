impl Solution {
    pub fn sort_people(names: Vec<String>, heights: Vec<i32>) -> Vec<String> {
        
        let n = names.len();
        
        let mut map:Vec<(i32, String)> = Vec::new();
        
        for i in 0..n {
            map.push((heights[i], names[i].clone()));
        }
        
        map.sort_by(|a,b| b.cmp(a));
        
        let mut res:Vec<String> = Vec::new();
        
        for i in 0..n {
            res.push(map[i].1.clone());
        }
        
        return res;
    }
}