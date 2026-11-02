class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        if(nums[0]==nums[n-1]) return 0;
        if(n%2==1){
            return deviation(nums, n/2);
        }
        else{
            return (deviation(nums, n/2), deviation(nums, n/2 - 1));
        }
        return -1;
    }

    int deviation(vector<int>&nums, int k){
        int cnt = 0;
        for(int &x:nums){
            cnt += abs(x-nums[k]);
        }
        return cnt;
    }
};