class Solution {
public:
    int mySqrt(int x) {
         if (x == 0 || x == 1) {
            return x;
        }
        int l = 1, 
            r = x/2;
        while (l <= r) {
            int m = l + (r - l)/2,
                mid = x/m;
            if (mid == m) {
                return m;
            } 
            if (mid < m) {
                r = m - 1;
            } else {
                l = m + 1;
            }
        }
        return r;
    }
};