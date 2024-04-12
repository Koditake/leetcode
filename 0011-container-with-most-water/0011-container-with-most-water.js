/**
 * @param {number[]} height
 * @return {number}
 */
var maxArea = function(height) {
    let n = height.length;
    
    if (n < 2) {
        return 0;
    }
    
    let l = 0,
        r = n - 1;
        v = 0;
    
    while (l < r) {
        v = Math.max(Math.min(height[r],height[l]) * (r - l), v);
        if (height[l] <= height[r]) {
            ++l;
        } else {
            --r;
        }
    }
    
    return v;
};