function maxArea(height: number[]): number {
    let l = 0, r = height.length - 1, volMax:number = 0
    
    while (l < r) {
        volMax = Math.max(volMax,Math.min(height[l],height[r])*(r - l));
        if (height[l] < height[r]) ++l; else --r;
    }
    
    return volMax
};