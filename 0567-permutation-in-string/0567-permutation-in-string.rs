impl Solution {
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let (n1,n2) = (s1.len(), s2.len());
        if n1 > n2 { return false; }
        
        let (charr1,charr2):(Vec<char>,Vec<char>) = (s1.chars().collect(),s2.chars().collect());
        let (mut m1, mut m2) = (vec![0;26], vec![0;26]);
        
        for i in 0..n1 {
            m1[charr1[i] as usize - 'a' as usize] += 1;
            m2[charr2[i] as usize - 'a' as usize] += 1;
        }
        
        if m1 == m2 { return true; }
        
        for i in n1..n2 {
            m2[charr2[i] as usize - 'a' as usize] += 1;
            m2[charr2[i - n1] as usize - 'a' as usize] -= 1;
            if m1 == m2 { return true; }
        }
        
        false
    }
}