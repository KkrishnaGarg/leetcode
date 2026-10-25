class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();
        int low = INT_MIN, high= 0;
        for(int w : weights){
            low = max(low, w); 
            high += w;
        }
        int ans;
        while(low<=high){
            int mid = (low+high)/2;
            if(possible(weights, days, mid)){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
    bool possible(vector<int>& nums, int days, int mid){
        int n = nums.size();
        int w = mid, d=0;
        for(int i=0; i<n; i++){
            if(nums[i]<=w){
                w -= nums[i];
            }
            else{
                d++;
                w = mid - nums[i];
            }
        }
        d++;
        if(d<=days) return true;
        else return false;
    }
};