class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0]*nums[0];
        for(auto &x : nums){
            x = abs(x);
        }
        sort(nums.begin(), nums.end());
        long long sum = 0;
        if(n%2==0){
            for(int i=0; i<n; i++){
                if(i<=(n-1)/2) sum -= nums[i]*nums[i];
                else sum += nums[i]*nums[i];
            }
        }
        if(n%2!=0){
            for(int i=0; i<n; i++){
                if(i<=(n-2)/2) sum -= nums[i]*nums[i];
                else sum += nums[i]*nums[i];
            }
        }
        return sum;
    }
};