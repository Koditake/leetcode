/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var search = function(nums, target) {
    let l = 0,
        r = nums.length - 1;
    
    while (l <= r) {
        let m = Math.floor((l + r) / 2);
        let mid = nums[m];
        
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