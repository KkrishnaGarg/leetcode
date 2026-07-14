class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int n = nums.size();
        int b1 = 0, b2 = 0;
        for(int i=0; i<n; i++){
            b1 = (b1^nums[i]) & ~b2;
            b2 = (b2^nums[i]) & ~b1;
        }
        return b1;
    }
};