class Solution {
public:
    double myPow(double x, int n) {
        long long N = 1ll * n;
        bool negative = false;
        if(n<0){
            negative = true;
            N *= -1;
        }
        double ans = 1.0;
        while(N){
            if(N%2 == 1){
                ans *= x;
                N--;
            }
            else{
                x *= x;
                N /= 2;
            }
        }
        if(!negative) return ans;
        return 1/ans;
    }
};