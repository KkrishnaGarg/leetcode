class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int ans = INT_MAX;

        while (low <= high) {
            int mid = (low + high) / 2;
            ans = min(ans, nums[mid]);

            while(nums[mid]==nums[low] && nums[mid]==nums[high]){
                low++;
                high--;
                if(low>=high) return ans;
            }

            if (nums[low] <= nums[mid]) {
                ans = min(ans, nums[low]);
                low = mid + 1;
            }
            
            else {
                ans = min(ans, nums[mid]);
                high = mid - 1;
            }
        }
        return ans;
    }
};