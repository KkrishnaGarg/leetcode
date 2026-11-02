class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[n-1]) return 0;
        int cnt = 0;
        for(int &x:nums){
            cnt += abs(x-nums[n/2]);
        }
        return cnt;
    }
};