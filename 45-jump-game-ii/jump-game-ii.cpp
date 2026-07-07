class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size(), l=0, r=0, jumps=0;
        while(r < n-1){
            int fartest = 0;
            for(int i=l; i<=r; i++){
                fartest = max(fartest, i+nums[i]);
            }
            l = r+1;
            r = fartest;
            jumps++;
        }
        return jumps;
    }
};