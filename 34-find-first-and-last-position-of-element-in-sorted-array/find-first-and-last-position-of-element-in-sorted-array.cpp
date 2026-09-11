class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        bool bs = binary_search(nums.begin(), nums.end(), target);
        if(!bs) return{-1, -1};
        int first = -1, last = nums.size();
        int low=0, high = nums.size()-1;
        while(high >= low){
            int mid = (low+high)/2;
            if(nums[mid]>=target){
                first = mid;
                high = mid-1;
            }
            else low = mid+1;
        }

        low=0, high = nums.size()-1;
        while(high >= low){
            int mid = (low+high)/2;
            if(nums[mid]>=target+1){
                last = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return {first, last-1};
    }
};