class Solution {
public:
    int trap(vector<int>& height) {
        // from left edge
        int l = 0,
            left = height[l],
            maxleft = 0;
        
        // from right edge
        int r = height.size() - 1,
            right = height[r],
            maxright = 0;
    
        // result
        int res = 0;

        while (l <= r) {
            int left = height[l],
                right = height[r];
            
            if (left < right) {
                if (left > maxleft) {
                    maxleft = left;
                } else {
                    res += maxleft - left;
                }
                l++;
            } else {
                if (right > maxright) {
                    maxright = right;
                } else {
                    res += maxright - right;
                }
                r--;
            }
        }

        return res;
    }
};