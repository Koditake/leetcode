function search(nums: number[], target: number): number {
    let l:number = 0,
        r:number = nums.length - 1;
    
    while (l <= r) {
        let m:number = Math.floor(l + (r - l)/2),
            mid = nums[m];
        
        if (mid < target) {
            l = m + 1;
        } else if (mid > target) {
            r = m - 1;
        } else {
            return m;        
        }
    }
    
    return -1;
};