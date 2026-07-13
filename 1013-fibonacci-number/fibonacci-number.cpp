class Solution {
public:
    int fib(int n) {
        vector<int> dp(n+1, -1);
        return fxn(n, dp);
    }
    int fxn(int n, vector<int>& dp) {
        if(dp[n]!=-1) return dp[n];
        if(n<2) return dp[n] = n;
        return dp[n] = fxn(n-1, dp)+fxn(n-2, dp);
    }
};