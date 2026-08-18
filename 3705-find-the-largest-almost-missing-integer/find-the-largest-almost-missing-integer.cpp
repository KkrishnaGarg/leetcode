class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        vector<int> hash(51,0);
        int n = nums.size();
        if(k == n){
            int maxi = nums[0];
            for(auto &x:nums){
                maxi = max(maxi,x);
            }
            return maxi;
        }
        for(auto &x : nums){
            hash[x]++;
        }
        if(k==1){
            for(int i=50; i>=0; i--){
                if(hash[i]==1) return i;
            }
        }
        if(nums[0]>nums[n-1]){
            if(hash[nums[0]]==1) return nums[0];
        }
        if(hash[nums[n-1]]==1) return nums[n-1];
        if(hash[nums[0]]==1) return nums[0];
        return -1;
    }
};