class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(sumOfDivision(piles, mid, h)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    bool sumOfDivision(vector<int>&nums, int d, int h){
        int n = nums.size();
        long long sum = 0;
        for(int i=0; i<n ;i++){
            sum += (nums[i]+d-1)/d;
        }
        if(sum <= 1ll*h) return true;
        else return false;
    }
};