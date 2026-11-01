class Solution {
public:
    int minMoves(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[n-1]) return 0;
        int cnt = 0;
        for(auto &x : nums){
            cnt += x-nums[0];
        }
        return cnt;
    }
};