class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;

        bool sign = true;
        if((dividend>=0 && divisor<0) || (dividend<0 && divisor>0)) sign = false;
        long long n =abs(1ll * dividend), d =abs(1ll * divisor), ans =0;

        while(n>=d){
            int cnt = 0;
            while(n >= d<<(cnt+1)){
                cnt++;
            }
            ans += 1<<cnt;
            n -= d<<cnt;
        }
        if(ans >= 1ll<<31 && sign) return INT_MAX;
        else if(ans >= 1ll<<31 && !sign) return INT_MIN;
        else if(sign) return ans;
        else return(-1 * ans);
        
    }
};