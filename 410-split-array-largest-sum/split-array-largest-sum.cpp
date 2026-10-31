class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = 0, high = 0;
        for(int i=0; i<n; i++){
            low = max(low, nums[i]);
            high += nums[i];
        }
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(nums, mid, k)) high = mid-1;
            else low = mid+1;
        }
        return low;
    }
    bool possible(vector<int>& nums, int mid, int k){
        int s=1, p=0, n=nums.size();
        for(int i=0; i<n; i++){
            if(p+nums[i]<=mid) p+=nums[i];
            else{
                s++;
                p = nums[i];
            }
        }
        if(s<=k) return true;
        else return false;
    }
};