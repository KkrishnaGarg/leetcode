class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = *max_element(nums.begin(), nums.end());
        int ans = high;
        while(low<=high){
            int mid = (low+high)/2;
            if(sumOfDivision(nums, mid, threshold)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    bool sumOfDivision(vector<int>&nums, int d, int threshold){
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n ;i++){
            sum += (nums[i]+d-1)/d;
        }
        if(sum <= 1ll*threshold) return true;
        else return false;
    }
};