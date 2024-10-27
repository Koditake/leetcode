func maxArea(height []int) int {
    l := 0; r := len(height) - 1; res := 0;
    for l < r {
        res = max(res,min(height[r],height[l]) * (r - l));
        if height[l] < height[r] {
            l += 1
        } else {
            r -= 1
        }
    }
    
    return res
}