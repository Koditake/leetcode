class Solution {
public:
    int finder(int n, int k){
        if (n == 1)
            return 0;
        return (finder(n - 1, k) + k) % n;
    }
    int findTheWinner(int n, int k) {
        return finder(n, k) + 1;   //+1 is for converting 0-based indexing to 1-based indexing
    }
};