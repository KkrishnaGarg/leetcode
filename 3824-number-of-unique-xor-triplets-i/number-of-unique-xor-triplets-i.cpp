class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;

        // return 1 << (32 - __builtin_clz(n));
        int i;
        for(i=31; i>=0; i--){
            if(n & 1<<i) break;
        }
        return pow(2,i+1);
    }
};