class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0,
            b = (int)sqrt(c);
        
        while (a <= b) {
            long t = a*a + b*b;
            if (t > c) {
                --b;
            } else if (t < c) {
                ++a;
            } else if (t == c) {
                return true;
            }
        }
        return false;
    }
};