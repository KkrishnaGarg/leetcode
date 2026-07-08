class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int x = nums[0];
        for(int i=1; i<nums.size(); i++){
            x = gcd(x, nums[i]);
            if(x==1) return true;
        }
        if(x==1) return true;
        return false;
    }
};