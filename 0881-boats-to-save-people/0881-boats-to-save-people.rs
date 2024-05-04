impl Solution {
    pub fn num_rescue_boats(people: Vec<i32>, limit: i32) -> i32 {
        let mut ppl = people.clone();
        ppl.sort();
        //let (mut l, mut r) = (0, ppl.len() - 1);
        let mut l:i32 = 0;
        let mut r:i32 = people.len() as i32 - 1;
        let mut res = 0;
        
        while (l <= r) {
            let sum = ppl[l as usize] + ppl[r as usize];
            if sum <= limit {
                l += 1;
                r -= 1;
            } else {
                r -= 1;
            }
            res += 1;
        }
        
        res
    }
}