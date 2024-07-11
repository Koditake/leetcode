function searchInsert(nums: number[], target: number): number {
    let l:number = 0,
        r:number = nums.length - 1
    
    while (l <= r) {
        let m = l + Math.floor((r - l)/2)
        
        if (nums[m] > target) {
            r = m - 1;
        } else if (nums[m] < target) {
            l = m + 1;
        } else {
            return m;
        }
    }
    
    return l;
};