class Solution {
public:
    const long long mod=1e9+7;
    long long dp[100001][2][3];
    long long f(int i, int absent, int late){
        if (absent >= 2 || late >= 3) 
            return 0;
        
        if (i == 0) 
            return 1;
        
        if (dp[i][absent][late] != -1) 
            return dp[i][absent][late];

        long long res = f(i-1, absent, 0);// P
        res += late < 2 ? f(i-1, absent, late+1):0;// L
        res += absent == 0 ? f(i-1, absent+1, 0):0;// A
       
        return dp[i][absent][late] = res % mod;
    }
    
    int checkRecord(int n) {
        fill(&dp[0][0][0], &dp[0][0][0]+(n+1)*6, -1);
        return f(n, 0, 0);
    }
};