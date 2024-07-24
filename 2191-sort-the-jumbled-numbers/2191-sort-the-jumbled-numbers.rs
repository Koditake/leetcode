impl Solution {
    pub fn sort_jumbled(mapping: Vec<i32>, nums: Vec<i32>) -> Vec<i32> {
        let mut vec_p:Vec<(i32, usize)> = Vec::new();
        
        for i in 0..nums.len() {
            vec_p.push((Self::switcharoo(&mapping,&nums[i]),i));
        }
            
        vec_p.sort();
    
        let mut res = Vec::new();
        
        for ps in vec_p {
            res.push(nums[ps.1]);
        }
            
        res
    }
    
    fn switcharoo(mapping: &Vec<i32>, num: &i32) -> i32 {
        if *num < 10 {
            return mapping[*num as usize];
        }
        
        let mut num_m = num.clone();
        let mut res:i32 = 0;
        let mut pow10:i32 = 1;
            
        while num_m > 0 {
            res += mapping[(num_m%10) as usize] * pow10;
            pow10 *= 10; num_m /= 10;
        }
        
        res
    }
}