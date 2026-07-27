class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int continuous =0;
        vector<int> arr;
        for(int i=0; i<nums.size(); i++){
            if(i==0){
                if(nums[i]==0) continuous=1;
            }
            else{
                if(nums[i]==0 && nums[i-1]==0) continuous++;
                else if(nums[i]==0) continuous=1;
                else if(nums[i]!=0 && continuous!=0){
                    arr.push_back(continuous);
                    continuous = 0;
                }
            }
        }
        if(continuous) arr.push_back(continuous);

        int n = arr.size();
        if(n==0) return 0;
        long long ans = 0;
        for(auto x : arr){
            ans += 1ll*x*(x+1)/2;
        }
        return ans;
    }
};