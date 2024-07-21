func singleNonDuplicate(nums []int) int {
    l := 0
    r := len(nums) - 1
    
    for l < r {
        m := l + (r - l)/2
        mid := nums[m]
        var mid_cmp int
        
        if m % 2 == 0 {
            mid_cmp = nums[m + 1]
        } else {
            mid_cmp = nums[m - 1]
        }
        
        if mid == mid_cmp {
            l = m + 1
        } else {
            r = m
        }
    }
    
    return nums[l]
}