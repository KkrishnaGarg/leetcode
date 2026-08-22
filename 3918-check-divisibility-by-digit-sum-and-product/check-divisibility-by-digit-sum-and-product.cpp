class Solution {
public:
    bool checkDivisibility(int n) {
        long long x = 1ll*n;
        long long sum = 0;
        long long product = 1;
        while(x>0){
            long long y = x%10;
            x /= 10;
            sum += y;
            product *= y; 
        }
        return !(n%(sum+product));
    }
};