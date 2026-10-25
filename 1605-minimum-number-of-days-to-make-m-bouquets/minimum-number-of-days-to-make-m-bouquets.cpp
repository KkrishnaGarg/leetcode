class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if(1ll*n < 1ll*m*k) return -1;
        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        int ans;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(possible(bloomDay, m, k, mid)){
                ans= mid;
                high = mid-1;
            }
            else low=mid+1;
        }
        return ans;
    }
    bool possible(vector<int>& nums, int bWant, int sze, int mid){
        int cnt = 0, n = nums.size();
        int b = 0;
        for(int i=0; i<n; i++){
            if(nums[i]<=mid)cnt++;
            else{
                b += cnt/sze;
                cnt=0;
            }
        }
        b += cnt/sze;
        if(b>=bWant) return true;
        else return false;
    }
};