function singleNonDuplicate(nums: number[]): number {
    let l = 0,
        r = nums.length - 1
    
    while (l < r) {
        let m = Math.floor((l + r) / 2)
        let num = nums[m]
        let num_cmp = m % 2 === 0 ? nums[m + 1]:nums[m - 1]
        
        if (num === num_cmp) 
            l = m + 1
        else
            r = m
    }
    
    return nums[l]
};