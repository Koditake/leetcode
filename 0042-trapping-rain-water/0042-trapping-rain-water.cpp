class Solution {
public:
    int trap(vector<int>& height) {
        if (height.size() <= 2) 
            return 0;
        
        int n = height.size(), 
            maxLeft = height[0], 
            maxRight = height[n-1];
        int left = 1, 
            right = n - 2, 
            res = 0;
        while (left <= right) {
            if (maxLeft < maxRight) {
                if (height[left] > maxLeft)
                    maxLeft = height[left];
                else
                    res += maxLeft - height[left];
                left += 1;
            } else {
                if (height[right] > maxRight)
                    maxRight = height[right];
                else
                    res += maxRight - height[right];
                right -= 1;
            }
        }
        return res;
    }
};