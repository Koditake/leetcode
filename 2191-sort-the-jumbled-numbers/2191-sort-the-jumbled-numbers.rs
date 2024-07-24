impl Solution {
    pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let mut vec_p: Vec<(i32, usize)> = nums.iter()
            .enumerate()
            .map(|(i, num)| (Self::switcharoo(&mapping, num), i))
            .collect();
        
        vec_p.sort();
    
        vec_p.into_iter()
            .map(|(mapped_num, original_idx)| nums[original_idx])
            .collect()
    }
    
    fn switcharoo(mapping: &[i32], num: &i32) -> i32 {
        if *num < 10 {
            mapping[*num as usize]
        } else {
            let mut num_m = num.clone();
            let (mut res, mut pow10) = (0, 1);
            
            while num_m > 0 {
                res += mapping[(num_m % 10) as usize] * pow10;
                pow10 *= 10;
                num_m /= 10;
            }
            
            res
        }
    }
}
