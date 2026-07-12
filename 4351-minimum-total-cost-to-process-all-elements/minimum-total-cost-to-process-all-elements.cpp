class Solution {
public:
    const int MOD = 1e9+7;
    int minimumCost(vector<int>& nums, int k) {
        long long r =k, mCost =0;
        for(auto x: nums){
            if(x>r){
                // x >= k * r
                long long need = (x-r+k-1)/k;
                r = r+ need*k;
                mCost = (mCost%MOD + need%MOD)%MOD;
            }
            r -= x;
        }
        return (((mCost)%MOD*(mCost+1)%MOD)%MOD * (500000004)%MOD)%MOD;
    }
};