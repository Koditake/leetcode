func maxArea(height []int) int {
    n := len(height); l := 0; r := n - 1;
    volMax := 0
    
    for (l < r) {
        volMax = max(min(height[l],height[r]) * (r - l),volMax)
        if height[l] < height[r] {
            l++
        } else {
            r--
        }
    }
    
    return volMax
}