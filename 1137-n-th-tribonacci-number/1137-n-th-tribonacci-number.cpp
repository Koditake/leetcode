class Solution {
public:
    int tribonacci(int n) {
        if (n == 0) return 0;
        if (n < 3) return 1;
        //if (n == 4) return 2;

        int a = 0; int b = 1; int c = 1;
        int sum;
        for (int i = 3; i <= n; i++)
        {
            sum = a + b + c;
            a = b;
            b = c;
            c = sum;
        }
        return sum;
    }
};