use std::collections::HashMap;

impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let (n1,n2) = (s1.len(), s2.len());
        if n1 > n2 { return false; }
        let (charr1, charr2):(Vec<char>, Vec<char>) = (s1.chars().collect(), s2.chars().collect());
        let mut m1 = HashMap::new();
        for c in charr1 {
            *m1.entry(c).or_insert(0) += 1;
        }
        
        for i in n1..n2 + 1 {
            let charr3 = &charr2[i - n1..i];
            let mut m2 = HashMap::new();
            for c in charr3 {
                *m2.entry(*c).or_insert(0) += 1;
            }
            
            if m1 == m2 { return true; }
        }
        
        false
    }
}