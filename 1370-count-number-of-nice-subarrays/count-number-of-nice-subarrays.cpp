class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        // for(int i=0; i<nums.size(); i++){
        //     if(nums[i]%2==0)nums[i]=0;
        //     else nums[i]=1;
        // }
        return fxn(nums, k) - fxn(nums, k-1);
    }

    int fxn(vector<int>& nums, int goal){
        if(goal<0) return 0;
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum += nums[r]%2;
            while(sum > goal){
                sum -= nums[l]%2;
                l++;
            }
            cnt += r-l+1;
            r++;
        }
        return cnt;
    }
};