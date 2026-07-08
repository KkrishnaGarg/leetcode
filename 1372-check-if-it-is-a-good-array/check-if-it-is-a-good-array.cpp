class Solution {
public:
    bool isGoodArray(vector<int>& nums) {
        int x = nums[0], n=nums.size();
        for(int i=1; i<n; i++){
            x = gcd(x, nums[i]);
            if(x==1) return true;
        }
        if(x==1) return true;
        return false;
    }
};