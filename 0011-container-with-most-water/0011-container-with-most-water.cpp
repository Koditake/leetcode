class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0,
            r = height.size() - 1,
            volMax = 0;
        
        while (l < r) {
            int vol = min(height[l],height[r]) * (r - l);
            volMax = max(vol,volMax);
            
            if (height[l] < height[r]) {
                ++l;
            } else {
                --r;
            }
        }
        
        return volMax;
    }
};