impl Solution {
    pub fn peak_index_in_mountain_array(arr: Vec<i32>) -> i32 {
        let mut l:i32 = 0;
        let mut r:i32 = arr.len() as i32 - 1;
        
        while l < r {
            let m = l + (r - l)/2;
            let (mid_m, mid_a) = (arr[m as usize], arr[(m + 1) as usize]);
            
            if (mid_m < mid_a) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        
        l
    }
}