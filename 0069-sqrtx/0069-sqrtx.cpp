class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) {
            return x;
        }

        long prec = 2;
        int post = 1;

        while (prec * prec <= x) {
            post++;
            prec++;
        } 

        return post;
    }
};