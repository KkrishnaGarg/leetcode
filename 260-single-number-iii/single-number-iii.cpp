class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x = 0;
        int n = nums.size();
        for(int i=0; i<n; i++){
            x = x ^ nums[i];
        }
        int r = (x & (x-1)) ^ x;
        int b1=0, b2=0;
        for(int i=0; i<n; i++){
            if(nums[i] & r)
                b1 = b1 ^ nums[i];
            else
                b2 = b2 ^ nums[i];
        }
        return {b1, b2};
    }
};