class Solution {
public:
    bool isPerfectSquare(int num) {
        int l = 0,  r = num;
        while (l <= r) {
            int m = l + (r - l)/2;
            auto tmp = (long long)m*m;
            if (tmp < num) l = m + 1;
            else if (tmp > num) r = m - 1;
            else return true;
        }
        
        return false;
    }
};